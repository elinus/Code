#include <iostream>
#include <string>
using namespace std;

class Int {
  int x;

public:
  Int(int x = 0) : x(x) { cout << __func__ << " called" << endl; }
  operator string() {
    cout << __func__ << " called" << endl;
    return to_string(x);
  }
};

class Base {};
class Derived : private Base {};
class Derived1 : public Base {};
class Derived2 : public Base {};

int main(int argc, char const *argv[]) {
  // 1. implicit conversion b/w types
  int i = 1;
  float f = 2.2;
  i = static_cast<int>(f);
  cout << "i = " << i << endl;

  // 2. With conversion oprator or ctor
  Int obj(3);
  string str_obj = obj;
  cout << str_obj << endl;
  obj = 20;
  obj = static_cast<Int>(30);

  // 3. static_cast is more restrictive
  char c = 'A';
  int *ip1 = (int *)(&c);
  *ip1 = 40;
  cout << "*ip1 = " << *ip1 << endl;
  // invalid static_cast from type 'char*' to type 'int*'
  //   int *ip2 = static_cast<int *>(&c);

  // 4. avoid cast from private base pointer
  Derived d1;
  Base *bp1 = (Base *)(&d1);
  // error: 'Base' is an inaccessible base of 'Derived'
  //   Base *bp2 = static_cast<Base *>(&d1);

  // 5. converting to-and-from void pointer
  int i2 = 10;
  void *vp = static_cast<void *>(&i2);
  int *i2p = static_cast<int *>(vp);

  // 6. use for all upcast, not for confused downcast
  Derived1 de1;
  Derived2 de2;
  Base *ba1 = static_cast<Base *>(&de1);
  Base *ba2 = static_cast<Base *>(&de2);
  Derived1 *de3 = static_cast<Derived1 *>(ba2); // Not allowed
  return 0;
}
