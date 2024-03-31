/*
 * RequestDispatcher.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef SERVER_IREQUESTDISPATCHER_H_
#define SERVER_IREQUESTDISPATCHER_H_
#include <string>

class IRequestDispatcher {
public:
	virtual ~IRequestDispatcher(){}

	virtual void handleRequest(std::string const& request) const = 0;
};

#endif /* SERVER_IREQUESTDISPATCHER_H_ */
