#include <exception>
#include <iostream>

using namespace std;

class Base {
public:
  virtual void coco() { cout << "Base::coco" << endl; };
};

class Derived1 : public Base {
public:
  void coco() override { cout << "Derived1::coco" << endl; };
};

class Derived2 : public Base {
public:
  void coco() override { cout << "Derived2::coco" << endl; };
};

int main(int argc, char const *argv[]) {
  Derived1 d1;
  Base *bp = dynamic_cast<Base *>(&d1);
  Derived2 *dp2 = dynamic_cast<Derived2 *>(bp);
  if (dp2 == nullptr) {
    cout << "nullptr" << endl;
  }
  Derived1 *dp1 = dynamic_cast<Derived1 *>(bp);
  if (dp1 != nullptr) {
    cout << "not nullptr" << endl;
    dp1->coco();
  }
  try {
    Derived2 &d2ref = dynamic_cast<Derived2 &>(d1);
  } catch (const exception &e) {
    cout << e.what() << endl;
  }
  return 0;
}
