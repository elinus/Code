#include <iostream>

using namespace std;

template <typename T> class auto_ptr2 {
  T *ptr;

public:
  auto_ptr2(T *ptr = nullptr) : ptr{ptr} {}
  ~auto_ptr2() {
    if (ptr)
      delete ptr;
    ptr = nullptr;
  }
  auto_ptr2(auto_ptr2 &other) {
    ptr = other.ptr;
    other.ptr = nullptr;
  }
  auto_ptr2 &operator=(auto_ptr2 &other) {
    if (this == &other)
      return *this;
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
  }
  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
  bool is_null() const { return ptr == nullptr; }
};

struct Resource {
  Resource() { cout << __func__ << endl; }
  ~Resource() { cout << __func__ << endl; }
  void sayHi() { cout << "Hi!\n"; }
};

int main(int argc, char const *argv[]) {
  auto_ptr2<Resource> res1{new Resource()};
  auto_ptr2<Resource> res2{res1};
  return 0;
}
