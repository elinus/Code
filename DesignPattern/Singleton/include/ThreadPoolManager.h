#ifndef __THREADPOOL_MANAGER_H__
#define __THREADPOOL_MANAGER_H__

#include <iostream>

class ThreadPoolManager {
public:
  static ThreadPoolManager *instance_;
  ~ThreadPoolManager();
  static ThreadPoolManager *GetInstance();
  void AddJob();
  void ExecuteJob();

private:
  ThreadPoolManager();
  ThreadPoolManager(const ThreadPoolManager &other) = delete;
  ThreadPoolManager &operator=(const ThreadPoolManager &other) = delete;
};

#endif /* __THREADPOOL_MANAGER_H__ */
