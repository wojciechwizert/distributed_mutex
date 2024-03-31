/*
 * ConcurentHashMap.h
 *
 *  Created on: Mar 13, 2024
 *      Author: ww
 */

#ifndef LOCKING_SYNCHRONIZEDLOCKMAP_H_
#define LOCKING_SYNCHRONIZEDLOCKMAP_H_
#include <unordered_map>
#include <optional>
#include <mutex>
#include <memory>

class LockEntry;

class SynchronizedLockMap {
	friend class LockEntry;
public:
	using LockEntryPtr = std::shared_ptr<LockEntry>;
	using LockId = long long;
	SynchronizedLockMap();
	~SynchronizedLockMap();

	bool exists(LockId id) const;
	LockEntryPtr computeIfAbsent(LockId id);
	void remove(LockId id);
private:
	std::unordered_map<LockId, LockEntryPtr > map_;
	mutable std::mutex synchroMutex_;
};

#endif /* LOCKING_SYNCHRONIZEDLOCKMAP_H_ */
