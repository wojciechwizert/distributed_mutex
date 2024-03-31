/*
 * SafeQueue.h
 *
 *  Created on: Mar 15, 2024
 *      Author: ww
 */

#ifndef UTILS_SAFEQUEUE_H_
#define UTILS_SAFEQUEUE_H_

#include <mutex>
#include <queue>
#include <iostream>

// Thread safe implementation of a Queue using an std::queue
template <typename T>
class SafeQueue {
private:
  std::queue<T> m_queue;
  std::mutex m_mutex;
public:

  bool empty() {
    std::unique_lock<std::mutex> lock(m_mutex);
    std::cout << "SafeQueue::empty" << std::endl;
    return m_queue.empty();
  }

  int size() {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.size();
  }

  void enqueue(T const& t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(t);
  }

T dequeue() {
    std::unique_lock<std::mutex> lock(m_mutex);

    if (m_queue.empty()) {
      return T{};
    }
    T t(std::move(m_queue.front()));

    m_queue.pop();
    return t;
  }
};

#endif /* UTILS_SAFEQUEUE_H_ */
