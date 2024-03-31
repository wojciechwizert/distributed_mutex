
/*
 * LockEntry.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef LOCKING_LOCKENTRY_H_
#define LOCKING_LOCKENTRY_H_
#include <mutex>
#include <memory>
class SynchronizedLockMap;

using MutexPtr = std::shared_ptr<std::mutex>;
using IntPtr = std::shared_ptr<int>;

class LockEntry {
	using LockId = long long;
public:
	friend class SynchronizedLockMap;
	LockEntry(SynchronizedLockMap* owner, LockId lockId);
	LockEntry(LockEntry const& aThat) = delete;
	LockEntry(LockEntry&& aThat) = delete;
	~LockEntry();

	void lock();
	void unlock();
private:
	SynchronizedLockMap* owner_;
	LockId lockId_;
	IntPtr locksCount_;

	MutexPtr entryMutex_;
	MutexPtr lockCountMutex_;
};

#endif /* LOCKING_LOCKENTRY_H_ */
