#include <algorithm>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

class ThreadTest {
public:
  void operator()() {
    std::cout << "thread " << std::this_thread::get_id() << " excuting .."
              << std::endl;
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::thread> threadVec;
  for (int i = 0; i < 10; i++) {
    threadVec.push_back(std::thread(ThreadTest()));
  }

  std::cout << "Waiting for all worker threads to finish" << std::endl;
  std::for_each(threadVec.begin(), threadVec.end(),
                std::mem_fn(&std::thread::join));
  std::cout << "exiting main { id = " << std::this_thread::get_id()
            << " } thread" << std::endl;
  return 0;
}
