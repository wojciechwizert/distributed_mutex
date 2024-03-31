/*
 * HttpSession.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef SERVER_HTTPSESSION_H_
#define SERVER_HTTPSESSION_H_
#include <string>
#include <memory>
#include <boost/asio.hpp>

class LockService;
class IRequestDispatcher;

class HttpSession : public std::enable_shared_from_this<HttpSession> {
public:
    HttpSession(std::shared_ptr<boost::asio::ip::tcp::socket> socket, IRequestDispatcher& dispatcher);

    void start();

private:
    void do_read();
    void handle_request(std::size_t length);
    void do_write(const std::string& response);

    std::shared_ptr<boost::asio::ip::tcp::socket> socket_;
    IRequestDispatcher& dispatcher_;
    enum { max_length = 1024 };
    char data_[max_length];
};

#endif /* SERVER_HTTPSESSION_H_ */
