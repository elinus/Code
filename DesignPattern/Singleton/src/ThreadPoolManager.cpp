#include "ThreadPoolManager.h"

#ifdef NO_DESTROY
ThreadPoolManager *ThreadPoolManager::instance_ = nullptr;

ThreadPoolManager *ThreadPoolManager::GetInstance() {

  std::cout << "{NO_DESTORY} ThreadPoolManager - GetInstance" << std::endl;
  if (!instance_) {
    instance_ = new ThreadPoolManager();
  }
  std::cout << "{NO_DESTROY} &instance_ : " << &instance_ << std::endl;
  return instance_;
}
#endif

#ifdef RESET_INSTANCE
ThreadPoolManager *ThreadPoolManager::instance_ = nullptr;

ThreadPoolManager *ThreadPoolManager::GetInstance() {

  std::cout << "{RESET_INSTANCE} ThreadPoolManager - GetInstance" << std::endl;
  if (!instance_) {
    instance_ = new ThreadPoolManager();
  }
  std::cout << "{RESET_INSTANCE} &instance_ : " << &instance_ << std::endl;
  return instance_;
}

void ThreadPoolManager::ResetInstance() {
  delete instance_;
  instance_ = nullptr;
}
#endif

ThreadPoolManager::ThreadPoolManager() {
  std::cout << "ThreadPoolManager - constructor" << std::endl;
}

ThreadPoolManager::~ThreadPoolManager() {
  std::cout << "ThreadPoolManager - destructor" << std::endl;
}

#ifdef STATIC_LOCAL_VARIABLE_SINGLETON
ThreadPoolManager *ThreadPoolManager::GetInstance() {

  std::cout << "ThreadPoolManager - GetInstance" << std::endl;
  static ThreadPoolManager inst_;
  std::cout << "&instance_ : " << &inst_ << std::endl;
  return &inst_;
}
#endif

void ThreadPoolManager::AddJob() { std::cout << "New job added!" << std::endl; }

void ThreadPoolManager::ExecuteJob() {
  std::cout << "Executing job ..!" << std::endl;
}
