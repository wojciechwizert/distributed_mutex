/*
 * LockEntry.cpp
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */
#include <iostream>
#include "LockEntry.h"
#include "SynchronizedLockMap.h"
#include "../exception/LockDeceasedException.h"

LockEntry::LockEntry(SynchronizedLockMap *owner,
		LockId lockId) :
		owner_(owner),
		lockId_(lockId),
		locksCount_(std::make_shared<int>(0)),
		entryMutex_(std::make_shared<std::mutex>()),
		lockCountMutex_(std::make_shared<std::mutex>()) {

}

LockEntry::~LockEntry() {}

void LockEntry::lock() {
	{
	std::cout << "Lock[" << lockId_ << "] before lockCount increment\n";
	std::lock_guard<std::mutex> l(*lockCountMutex_);
		if(!owner_->exists(lockId_)) {
			throw LockDeceasedException("Lock has been removed from the LockMap");
		}
		++*locksCount_;
		std::cout << "Lock[" << lockId_ << "] after lockCount increment\n";
	}
	std::cout << "Lock[" << lockId_ << "] before lock operation\n";
	entryMutex_->lock();
	std::cout << "Lock[" << lockId_ << "] after lock operation\n";
}

void LockEntry::unlock() {
	std::lock_guard<std::mutex> l(*lockCountMutex_);
		*locksCount_=std::max(0, *locksCount_ -1);
		entryMutex_->unlock();
		if(*locksCount_ == 0) {
			owner_->remove(lockId_);;
		}
}
