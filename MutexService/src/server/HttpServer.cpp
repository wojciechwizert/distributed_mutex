/*
 * HttpServer.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#include "HttpServer.h"
#include "HttpSession.h"
#include "../utils/ThreadPool.h"
#include <boost/asio.hpp>
#include <memory>

HttpServer::HttpServer(boost::asio::io_service &io_service, short port,
		IRequestDispatcher &dispatcher,
		boost::asio::thread_pool& pool) :
		io_service_(io_service),
		acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
		dispatcher_(dispatcher),
		threadPool_(pool){
	do_accept();
}

void HttpServer::do_accept() {
	std::shared_ptr<boost::asio::ip::tcp::socket> s = std::make_shared<boost::asio::ip::tcp::socket>(io_service_);
	acceptor_.async_accept(*s,
			[this, s](boost::system::error_code ec) {
				if (!ec) {
//					threadPool_.submit([s, this]{
//						auto sessionPtr = std::make_shared<HttpSession>(s,this->dispatcher_);
//						sessionPtr->start();
//					});
					boost::asio::post(threadPool_, [s, this]{
													auto sessionPtr = std::make_shared<HttpSession>(s,this->dispatcher_);
													sessionPtr->start();
												});
				}

				do_accept();
			});
}

