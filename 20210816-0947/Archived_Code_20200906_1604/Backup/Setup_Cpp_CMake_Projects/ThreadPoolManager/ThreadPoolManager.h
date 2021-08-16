#ifndef __THREADPOOLMANAGER_H__
#define __THREADPOOLMANAGER_H__

#include <iostream>
#include <mutex>
#include <string>
#include <vector>

class ThreadPoolManager {
    private:
        static ThreadPoolManager* m_spInstance;
        static std::mutex m_sLock;
        std::vector<std::string> m_Tasks;
        ThreadPoolManager();
        ThreadPoolManager(const ThreadPoolManager &other) = delete;
        ThreadPoolManager& operator=(const ThreadPoolManager &other) = delete;
    public:
        ~ThreadPoolManager();
        static ThreadPoolManager* GetThreadPoolManager();
        static void DestroyThreadPoolManagerInstance();
        size_t Size() const;
        void AddTask(const std::string &task);
        std::string GetTask(size_t index) const;
};

#endif /* __THREADPOOLMANAGER_H__ */
