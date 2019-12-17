#include <iostream>

using namespace std;

class Base {
  virtual void dummy() {}
};
class Derived : public Base {};

int main(int argc, char *argv[]) {
  Base *b1 = new Derived;
  Base *b2 = new Base;
  Derived *d1 = dynamic_cast<Derived *>(b1);
  Derived *d2 = dynamic_cast<Derived *>(b2);
  return 0;
}
