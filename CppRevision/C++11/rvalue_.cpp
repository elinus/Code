#include <iostream>

class Test {
private:
  int counter;

public:
  Test() { counter = 14; }
  void increment() { counter++; }
};

Test getTestObj() { return Test(); }

int main(int argc, char *argv[]) {
  getTestObj().increment();
  return 0;
}
