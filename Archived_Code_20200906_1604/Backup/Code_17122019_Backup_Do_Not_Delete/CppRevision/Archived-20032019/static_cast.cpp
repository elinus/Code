#include <iostream>

using namespace std;

class Base {};

class Derived : public Base {};

int main(int argc, char *argv[]) {
  Base *b1 = new Base;
  Derived *d1 = static_cast<Derived *>(b1);

  Derived *d2 = new Derived;
  Base *b2 = static_cast<Base *>(d2);

  double d = 3.14159265;
  int i = static_cast<int>(d);
  cout << d << " " << i << endl;

  return 0;
}
