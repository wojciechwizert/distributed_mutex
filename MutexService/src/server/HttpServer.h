/*
 * HttpServer.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef SERVER_HTTPSERVER_H_
#define SERVER_HTTPSERVER_H_
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

class IRequestDispatcher;
class ThreadPool;

class HttpServer {
public:
    HttpServer(boost::asio::io_service& io_service, short port, IRequestDispatcher& dispatcher, boost::asio::thread_pool& pool);

private:
    void do_accept();

    boost::asio::io_service& io_service_;
    boost::asio::ip::tcp::acceptor acceptor_;
    IRequestDispatcher& dispatcher_;
    boost::asio::thread_pool& threadPool_;
};

#endif /* SERVER_HTTPSERVER_H_ */
