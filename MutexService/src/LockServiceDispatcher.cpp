/*
 * LockServiceDispatcher.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#include "LockServiceDispatcher.h"
#include <sstream>
#include <iostream>

LockServiceDispatcher::LockServiceDispatcher() {
	// TODO Auto-generated constructor stub

}

LockServiceDispatcher::~LockServiceDispatcher() {
	// TODO Auto-generated destructor stub
}

void LockServiceDispatcher::handleRequest(std::string const& request) const {
	std::istringstream request_stream(request);
	std::string method, uri, version;
	request_stream >> method >> uri >> version;
	std::cout << "uri.substr(0, 10) = " << uri.substr(0, 10) << std::endl;
	std::cout << "uri.substr(0, 12) = " << uri.substr(0, 12) << std::endl;

	if (method == "GET" && uri.substr(0, 10) == "/api/lock/") {
		int lockId = std::stoi(uri.substr(10));
		std::cout << "lockId = " << lockId << std::endl;
		lockService_.lock(lockId);
	} else if (method == "GET" && uri.substr(0, 12) == "/api/unlock/") {
		int lockId = std::stoi(uri.substr(12));
		std::cout << "lockId = " << lockId << std::endl;
		lockService_.unlock(lockId);
	} else {
		std::cout << "uri = " << uri << std::endl;
		throw std::invalid_argument("Unknown uri");
	}
}

void LockServiceDispatcher::doHandle(std::string const& request) const {

}

