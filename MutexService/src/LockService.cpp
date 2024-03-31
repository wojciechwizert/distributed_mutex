/*
 * LockService.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#include "LockService.h"
#include "exception/LockDeceasedException.h"

LockService::LockService() {}
LockService::~LockService() {}

void LockService::lock(LockId lockId) const {
	while(true) {
		try {
			auto lock = lockMap_.computeIfAbsent(lockId);
			lock->lock();
		} catch (LockDeceasedException& e) {
			continue;
		}
		break;
	}
}
void LockService::unlock(LockId lockId) const {
	auto lock = lockMap_.computeIfAbsent(lockId);
	lock->unlock();
}

