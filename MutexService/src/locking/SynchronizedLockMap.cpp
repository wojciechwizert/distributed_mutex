#include "SynchronizedLockMap.h"
#include "LockEntry.h"

SynchronizedLockMap::SynchronizedLockMap() {
}
SynchronizedLockMap::~SynchronizedLockMap() {
}

SynchronizedLockMap::LockEntryPtr SynchronizedLockMap::computeIfAbsent(LockId id) {
	std::lock_guard<std::mutex> l(synchroMutex_);
	auto it = map_.find(id);
	if (it == map_.end()) {
		it = map_.emplace(id, std::make_shared<LockEntry>(this, id)).first;
	}
	return it->second;
}

bool SynchronizedLockMap::exists(LockId id) const {
	std::lock_guard<std::mutex> l(synchroMutex_);
	return map_.contains(id);
}

void SynchronizedLockMap::remove(LockId id) {
	std::lock_guard<std::mutex> l(synchroMutex_);
	map_.erase(id);
}
