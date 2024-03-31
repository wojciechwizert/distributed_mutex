//============================================================================
// Name        : MutexService.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <thread>
#include <boost/lexical_cast.hpp>
#include "LockServiceDispatcher.h"
#include "server/HttpServer.h"
#include "utils/ThreadPool.h"
using namespace std;

int port = 8080;
unsigned int poolSize = 256;

int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	try {

		boost::asio::io_service io_service;
		LockServiceDispatcher LockServiceDispatcher;
	    std::cout << "Max number of threads that can run simultaneously: " << std::thread::hardware_concurrency() << std::endl;
//		ThreadPool pool(poolSize);
		boost::asio::thread_pool boost_thread_pool(50);
//		boost_thread_pool.attach();
//		pool.init();
		HttpServer server(io_service, port, LockServiceDispatcher, boost_thread_pool);
		io_service.run();
		boost_thread_pool.join();
		boost_thread_pool.stop();
//		pool.shutdown();
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}
