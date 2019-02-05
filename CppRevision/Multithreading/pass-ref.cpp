#include <functional>
#include <iostream>
#include <string>
#include <thread>

void foo(int const &x) {
  int &y = const_cast<int &>(x);
  y++;
  std::cout << "value inside = " << x << std::endl;
}

int main(int argc, char *argv[]) {
  int i = 14;
  std::cout << "value before: " << i << std::endl;
  std::thread t1(foo, std::ref(i));

  t1.join();

  std::cout << "value = " << i << "\nmain: " << std::this_thread::get_id()
            << std::endl;
  return 0;
}
