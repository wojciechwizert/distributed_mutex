/*
 * ThreadPool.h
 *
 *  Created on: Mar 15, 2024
 *      Author: ww
 */

#ifndef UTILS_THREADPOOL_H_
#define UTILS_THREADPOOL_H_

#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>

#include "SafeQueue.h"

class ThreadPool {
private:
	class ThreadWorker {
	private:
		int m_id;
		ThreadPool *m_pool;
	public:
		ThreadWorker(ThreadPool *pool, const int id) :
			 	m_id(id),
				m_pool(pool){
		}

		void operator()() {
			std::function<void()> func;
			while (!m_pool->m_shutdown.load(std::memory_order_relaxed)) {
				{
					std::unique_lock<std::mutex> lock(
							m_pool->m_conditional_mutex);
					while (m_pool->m_queue.empty()) {
						m_pool->m_conditional_lock.wait(lock);
					}
					func = std::move(m_pool->m_queue.dequeue());
				}
				func();
			}
		}
	};

	std::atomic<bool> m_shutdown;
	std::vector<std::thread> m_threads;
	SafeQueue<std::function<void()>> m_queue;
	std::mutex m_conditional_mutex;
	std::condition_variable m_conditional_lock;
public:
	ThreadPool(const int n_threads) :
		 	m_shutdown(false),
			m_threads(std::vector<std::thread>(n_threads)) {
	}

	ThreadPool(const ThreadPool&) = delete;
	ThreadPool(ThreadPool&&) = delete;

	ThreadPool& operator=(const ThreadPool&) = delete;
	ThreadPool& operator=(ThreadPool&&) = delete;

	// Inits thread pool
	void init() {
		for (std::size_t i = 0; i < m_threads.size(); ++i) {
			m_threads[i] = std::thread(ThreadWorker(this, i));
		}
	}

	// Waits until threads finish their current task and shutdowns the pool
	void shutdown() {
		m_shutdown.store(true, std::memory_order_relaxed);
		m_conditional_lock.notify_all();

		for (std::size_t i = 0; i < m_threads.size(); ++i) {
			if (m_threads[i].joinable()) {
				m_threads[i].join();
			}
		}
	}

	// Submit a function to be executed asynchronously by the pool
	template<typename F, typename ...Args>
	auto submit(F &&f, Args &&... args) -> std::future<decltype(f(args...))> {
		// Create a function with bounded parameters ready to execute
		std::function<void()> wrapper = [&] { std::forward<F>(f)(args...); };
		std::function<decltype(f(args...))()> func = std::bind(
				std::forward<F>(f), std::forward<Args>(args)...);
		// Encapsulate it into a shared ptr in order to be able to copy construct / assign
		auto task_ptr = std::make_shared<
				std::packaged_task<decltype(f(args...))()>>(func);

		// Wrap packaged task into void function
		std::function<void()> wrapper_func = [task_ptr]() {
			(*task_ptr)();
		};

		// Enqueue generic wrapper function
		m_queue.enqueue(wrapper_func);

		// Wake up one thread if its waiting
		m_conditional_lock.notify_one();

		// Return future from promise
		return task_ptr->get_future();
	}
};
#endif /* UTILS_THREADPOOL_H_ */
