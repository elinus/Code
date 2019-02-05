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
  std::thread t1((ThreadTest()));
  if (t1.joinable()) {
    std::cout << "detaching thread " << t1.get_id() << std::endl;
    t1.detach();
  }

  if (t1.joinable()) {
    std::cout << "detaching thread " << t1.get_id() << std::endl;
    t1.detach();
  }

  std::thread t2((ThreadTest()));
  if (t2.joinable()) {
    std::cout << "join thread " << t2.get_id() << std::endl;
    t2.join();
  }

  if (t2.joinable()) {
    std::cout << "join thread " << t2.get_id() << std::endl;
    t2.join();
  }

  std::cout << "exiting main { id = " << std::this_thread::get_id()
            << " } thread" << std::endl;
  return 0;
}
