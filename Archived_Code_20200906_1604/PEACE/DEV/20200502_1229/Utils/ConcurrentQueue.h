#ifndef __CONCURRENT_QUEUE_H__
#define __CONCURRENT_QUEUE_H__

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class ConcurrentQueue {
    private:
        std::queue<T> m_Queue;
        std::mutex m_Mutex;
        std::condition_variable m_CV;
    public:
        T pop() {
            std::unique_lock<std::mutex> lock(m_Mutex);
            while (m_Queue.empty())
            {
                m_CV.wait(lock);
            }
            auto item = m_Queue.front();
            m_Queue.pop();
            return item;
        }

        void pop(T& item) {
            std::unique_lock<std::mutex> lock(m_Mutex);
            while (m_Queue.empty())
            {
                m_CV.wait(lock);
            }
            item = m_Queue.front();
            m_Queue.pop();
        }

        void push(const T& item) {
            std::unique_lock<std::mutex> lock(m_Mutex);
            m_Queue.push(item);
            lock.unlock();
            m_CV.notify_one();
        }

        void push(T&& item) {
            std::unique_lock<std::mutex> lock(m_Mutex);
            m_Queue.push(std::move(item));
            lock.unlock();
            m_CV.notify_one();
        }

        size_t size() {
            std::lock_guard<std::mutex> lock(m_Mutex);
            return m_Queue.size();
        }

        bool empty() {
            std::lock_guard<std::mutex> lock(m_Mutex);
            return m_Queue.empty();
        }
};

#endif /* __CONCURRENT_QUEUE_H__ */

