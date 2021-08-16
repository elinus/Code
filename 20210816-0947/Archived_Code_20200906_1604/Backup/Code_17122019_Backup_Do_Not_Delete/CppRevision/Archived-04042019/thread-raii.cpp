#include <iostream>
#include <thread>

class ThreadRAII {
public:
  ThreadRAII(std::thread &threadObj) : mThread(threadObj) {}
  ~ThreadRAII() {
    if (mThread.joinable()) {
      mThread.detach();
    }
  }

private:
  std::thread &mThread;
};

void foo() {
  for (int i = 0; i < 10; i++) {
    std::cout << "thread function executing.. id = "
              << std::this_thread::get_id() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::thread t1(foo);
  ThreadRAII trObj(t1);
  return 0;
}
