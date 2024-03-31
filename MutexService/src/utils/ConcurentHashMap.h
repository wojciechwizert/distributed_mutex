/*
 * ConcurentHashMap.h
 *
 *  Created on: Mar 14, 2024
 *      Author: ww
 */

#ifndef UTILS_CONCURENTHASHMAP_H_
#define UTILS_CONCURENTHASHMAP_H_
#include <unordered_map>
#include <mutex>
#include <functional>
#include <optional>
#include <memory>

template<typename K, typename V>
class ConcurentHashMap {
public:
	ConcurentHashMap();
	virtual ~ConcurentHashMap();

	V getOrCompute(K const& k, std::function<V(K const& k)> defaultProvider = []{ return V{};}) {
		SynchedEntryPtr vEntry = map_[k];
		std::lock_guard<std::mutex> l(vEntry->m);
			if(!vEntry->value) {
				vEntry->value=std::move(defaultProvider(k));
			}
			return *vEntry->value;
	}

	void add(K const& k, V&& v) {
		SynchedEntryPtr vEntry = map_[k];
		std::lock_guard<std::mutex> l(vEntry->m);
			vEntry->value=std::forward<V>(v);
	}

	void remove(K const& k) {
		SynchedEntryPtr vEntry = map_[k];
			std::lock_guard<std::mutex> l(vEntry->m);
				map_.erase(vEntry);
	}

private:
	struct SynchedEntry{
		SynchedEntry() : value(std::nullopt) {}
		SynchedEntry(V&& v) : value(std::forward<V>(v)) {}
		~SynchedEntry() {}
		std::optional<V> value;
		std::mutex m;
	};
	using SynchedEntryPtr = std::shared_ptr<SynchedEntry>;
	std::unordered_map<K, SynchedEntryPtr> map_;
};

#endif /* UTILS_CONCURENTHASHMAP_H_ */
