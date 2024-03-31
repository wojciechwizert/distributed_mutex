/*
 * HttpSession.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#include "HttpSession.h"
#include "IRequestDispatcher.h"
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

HttpSession::HttpSession(std::shared_ptr<boost::asio::ip::tcp::socket> socket,
		IRequestDispatcher& dispatcher) :
		socket_(socket), dispatcher_(dispatcher) {
}

void HttpSession::start() {
	do_read();
}

void HttpSession::do_read() {
	auto self(shared_from_this());
	boost::system::error_code ec;
	std::size_t length = socket_->read_some(boost::asio::buffer(data_, max_length), ec);
	if(!ec)
		handle_request(length);
}

void HttpSession::handle_request(std::size_t length) {
	std::string request(data_, length);
	std::istringstream request_stream(request);
	std::string method, uri, version;
	request_stream >> method >> uri >> version;

	try {
		dispatcher_.handleRequest(request);
	} catch (std::invalid_argument& e) {
		do_write("HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
	}
	do_write("HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n");
}

void HttpSession::do_write(const std::string &response) {
	auto self(shared_from_this());
	boost::system::error_code ec;
	boost::asio::write(*socket_, boost::asio::buffer(response), ec);
	if (!ec) {
		socket_->shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
	}
}
