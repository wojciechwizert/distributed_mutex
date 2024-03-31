/*
 * LockServiceDispatcher.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef LOCKSERVICEDISPATCHER_H_
#define LOCKSERVICEDISPATCHER_H_

#include "LockService.h"
#include "server/IRequestDispatcher.h"

class LockServiceDispatcher: public IRequestDispatcher {
public:
	LockServiceDispatcher();
	virtual ~LockServiceDispatcher();
	void handleRequest(std::string const& request) const override;

private:
	void doHandle(std::string const& request) const;
	LockService lockService_;
};

#endif /* LOCKSERVICEDISPATCHER_H_ */
