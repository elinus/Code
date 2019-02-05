#include "ThreadPoolManager.h"
#include <iostream>
#include <thread>
#include <vector>

void AssignAndExecuteTask() {
  std::cout << "Assigning and excuting task [tid = "
            << std::this_thread::get_id() << "]" << std::endl;
  ThreadPoolManager *manager1 = ThreadPoolManager::GetInstance();
  manager1->AddJob();
  manager1->ExecuteJob();
}

int main() {

  std::vector<std::thread> thVec;
  int n_threads = 10;
  for (int i = 0; i < n_threads; ++i) {
    thVec.emplace_back(AssignAndExecuteTask);
  }

  for (auto &th : thVec) {
    if (th.joinable()) {
      std::cout << "Joining thread [tid = " << th.get_id() << "]" << std::endl;
      th.join();
    }
  }

  std::cout << "Exiting main [tid = " << std::this_thread::get_id() << "]"
            << std::endl;

  return 0;
}
