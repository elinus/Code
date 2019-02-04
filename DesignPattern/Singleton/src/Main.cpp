#include "ThreadPoolManager.h"
#include <iostream>

int main() {

  ThreadPoolManager *manager1 = ThreadPoolManager::GetInstance();
  manager1->AddJob();
  manager1->ExecuteJob();

  ThreadPoolManager *manager2 = ThreadPoolManager::GetInstance();
  manager2->AddJob();
  manager2->ExecuteJob();

  return 0;
}
