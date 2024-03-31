/*
 * ConnectionPool.h
 *
 *  Created on: Mar 31, 2024
 *      Author: ww
 */

#ifndef UTILS_CONNECTIONPOOL_H_
#define UTILS_CONNECTIONPOOL_H_

class ConnectionPool {
public:
	ConnectionPool();
	virtual ~ConnectionPool();
	ConnectionPool(ConnectionPool const& aThat) = default;
};

#endif /* UTILS_CONNECTIONPOOL_H_ */
