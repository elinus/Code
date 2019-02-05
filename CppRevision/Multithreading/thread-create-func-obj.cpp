#include <iostream>
#include <thread>

class Test {
public:
  void operator()() {
    for (int i = 0; i < 10; i++) {
      std::cout << "thread function executing.. [ id = "
                << std::this_thread::get_id() << " ]" << std::endl;
    }
  }
};

int main(int argc, char *argv[]) {
  std::thread t1((Test()));
  for (int i = 0; i < 10; i++) {
    std::cout << "main function executing.. { id = " << t1.get_id() << " }"
              << std::endl;
  }

  t1.join();
  std::cout << "Exiting main function!" << std::endl;
  return 0;
}
