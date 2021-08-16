#include <iostream>

using namespace std;

template <typename T> class auto_ptr1 {
  T *ptr;

public:
  auto_ptr1(T *ptr = nullptr) : ptr{ptr} {}
  ~auto_ptr1() {
    if (ptr)
      delete ptr;
    ptr = nullptr;
  }
  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
};

struct Resource {
  Resource() { cout << __func__ << endl; }
  ~Resource() { cout << __func__ << endl; }
  void sayHi() { cout << "Hi!\n"; }
};

int main(int argc, char const *argv[]) {
  auto_ptr1<Resource> res1{new Resource()};
  auto_ptr1<Resource> res2{res1};
  return 0;
}
