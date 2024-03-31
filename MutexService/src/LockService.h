/*
 * LockService.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef LOCKSERVICE_H_
#define LOCKSERVICE_H_
#include "locking/LockEntry.h"
#include "locking/SynchronizedLockMap.h"

class LockService {
	using LockId = long long;
public:
	LockService();
	~LockService();

	void lock(LockId lockId) const;
	void unlock(LockId lockId) const;
private:
	mutable SynchronizedLockMap lockMap_;

};

#endif /* LOCKSERVICE_H_ */
