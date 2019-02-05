#include <iostream>
#include <thread>

class Test {
public:
  Test() {}
  Test(const Test &obj) {}
  void print(int x) { std::cout << "Inside print " << x << std::endl; }
};

int main() {

  Test obj;
  int x = 10;
  std::thread t1(&Test::print, &obj, x);
  t1.join();
  return 0;
}
