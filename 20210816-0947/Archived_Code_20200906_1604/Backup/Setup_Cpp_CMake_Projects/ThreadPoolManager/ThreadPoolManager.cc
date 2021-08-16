#include "ThreadPoolManager.h"

std::mutex ThreadPoolManager::m_sLock;
ThreadPoolManager* ThreadPoolManager::m_spInstance = nullptr;

ThreadPoolManager::ThreadPoolManager() {
    std::cout << "{ " << this << " } ThreadPoolManager instance created!\n";
}

ThreadPoolManager::~ThreadPoolManager() {
    std::cout << "{ " << this << " } ThreadPoolManager instance deleted!!\n";
}

ThreadPoolManager* ThreadPoolManager::GetThreadPoolManager() {
    if (m_spInstance == nullptr) {
        m_sLock.lock();
        if (m_spInstance == nullptr) {
            m_spInstance = new ThreadPoolManager();
        }
        m_sLock.unlock();
    }
    return m_spInstance;
}

void ThreadPoolManager::DestroyThreadPoolManagerInstance() {
    delete m_spInstance;
    m_spInstance = nullptr;
}

size_t ThreadPoolManager::Size() const {
    return m_Tasks.size();
}
        
void ThreadPoolManager::AddTask(const std::string& task) {
    m_Tasks.push_back(task);
}
        
std::string ThreadPoolManager::GetTask(size_t index) const {
    if (index >= 0 && index < m_Tasks.size()) {
        return m_Tasks[index];
    } else {
        return "";
    }
}
