#include "ThreadPoolManager.h"

ThreadPoolManager *ThreadPoolManager::instance_ = nullptr;

ThreadPoolManager::ThreadPoolManager() {
  std::cout << "ThreadPoolManager - constructor" << std::endl;
}

ThreadPoolManager::~ThreadPoolManager() {
  std::cout << "ThreadPoolManager - destructor" << std::endl;
}

ThreadPoolManager *ThreadPoolManager::GetInstance() {

  std::cout << "ThreadPoolManager - GetInstance" << std::endl;
  if (!instance_) {
    instance_ = new ThreadPoolManager();
  }
  std::cout << "&instance_ : " << &instance_ << std::endl;
  return instance_;
}

void ThreadPoolManager::AddJob() { std::cout << "New job added!" << std::endl; }

void ThreadPoolManager::ExecuteJob() {
  std::cout << "Executing job ..!" << std::endl;
}
