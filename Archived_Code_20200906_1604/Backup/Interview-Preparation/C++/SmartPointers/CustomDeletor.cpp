#include <iostream>
#include <memory>

void DeleteIntArray(int *arr) {
  std::cout << "***** Deleting Integer Array *****\n";
  std::cout << "arr = " << arr << "\n";
  delete[] arr;
}

struct Foo {
  Foo() { std::cout << this << " :: Foo()\n"; }
  ~Foo() { std::cout << this << " :: ~Foo()\n"; }
};

void DeleteFooArray(Foo *arr) {
  std::cout << "***** Deleting Foo Array *****\n";
  std::cout << "arr = " << arr << "\n";
  delete[] arr;
}

class Deletor {
public:
  void operator()(Foo *arr) {
    std::cout << "Delete Foo Using Function Object!\n";
    std::cout << "arr = " << arr << "\n";
    delete[] arr;
  }
};

int main(int argc, char const *argv[]) {
  std::shared_ptr<int> p1(new int[14], DeleteIntArray);
  std::cout << "p1 = " << p1 << ", use_count = " << p1.use_count() << "\n";

  std::shared_ptr<Foo> p2(new Foo[5], DeleteFooArray);
  // Using Function Object
  std::shared_ptr<Foo> p3(new Foo[5], Deletor());
  // Delete using lambda
  std::shared_ptr<Foo> p4(new Foo[5], [](Foo *x) {
    std::cout << "***** Deleting Foo Array *****\n";
    std::cout << "axr = " << x << "\n";
    delete[] x;
  });
  return 0;
}
