#ifndef __THREADPOOL_MANAGER_H__
#define __THREADPOOL_MANAGER_H__

#include <iostream>

class ThreadPoolManager {
public:
#ifdef NO_DESTROY
  static ThreadPoolManager *instance_;
#endif
  ~ThreadPoolManager();
  static ThreadPoolManager *GetInstance();
  void AddJob();
  void ExecuteJob();
#ifdef RESET_INSTANCE
  static ThreadPoolManager *instance_;
  static void ResetInstance();
#endif
private:
  ThreadPoolManager();
  ThreadPoolManager(const ThreadPoolManager &other) = delete;
  ThreadPoolManager &operator=(const ThreadPoolManager &other) = delete;
};

#endif /* __THREADPOOL_MANAGER_H__ */
