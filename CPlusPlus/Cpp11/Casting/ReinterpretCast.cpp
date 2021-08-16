#include <iostream>
#include <memory>
using namespace std;

class Mango {
public:
  Mango() { cout << __func__ << " called" << endl; }
  void eatMango() { cout << __func__ << " called" << endl; }
};

class Banana {
public:
  Banana() { cout << __func__ << " called" << endl; }
  void eatBanana() { cout << __func__ << " called" << endl; }
};

struct MyStruct {
  int x, y;
  char c;
  bool b;
  MyStruct() : x(14), y(20), c('A'), b(true) {}
};

int main(int argc, char const *argv[]) {
  Mango *m = new Mango();
  Banana *b = new Banana();
  Banana *nb = reinterpret_cast<Banana *>(m);
  nb->eatBanana();
  //   nb->eatMango(); // error: 'class Banana' has no member named 'eatMango'

  MyStruct ms;
  cout << "ms = " << &ms << ", size of (MyStruct) = " << sizeof(ms) << endl;
  int *p = reinterpret_cast<int *>(&ms);
  cout << "p = " << p << ", *p = " << *p << endl;
  p++;
  cout << "p = " << p << ", *p = " << *p << endl;

  char *c = reinterpret_cast<char *>(++p);
  cout << "c = " << static_cast<void *>(c) << ", *c = " << *c << endl;

  bool *bp = reinterpret_cast<bool *>(++c);
  cout << "bp = " << bp << ", *bp = " << *bp << endl;
  return 0;
}
