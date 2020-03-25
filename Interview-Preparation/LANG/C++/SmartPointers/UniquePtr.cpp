#include <iostream>
#include <memory>

class UniquePtr {
public:
  UniquePtr() { std::cout << this << " :: UniquePtr()\n"; }
  ~UniquePtr() { std::cout << this <<" :: ~UniquePtr()\n"; }
};

int main(int argc, char const *argv[]) {
  std::unique_ptr<UniquePtr> p0;
  if (p0 == nullptr) {
    std::cout << "p0 = nullptr\n";
  }

  std::unique_ptr<UniquePtr> p1(new UniquePtr());

  if (p1 != nullptr) {
    std::cout << "p1 != nullptr\n";
  }

  std::unique_ptr<UniquePtr> p2 = std::move(p1);

  if (p1 == nullptr) {
    std::cout << "p1 = nullptr\n";
  }

  if (p2 != nullptr) {
    std::cout << "p2 != nullptr\n";
  }

  std::cout << "Reseting p2!\n";
  p2.reset();
  if (p2 == nullptr) {
    std::cout << "p2 = nullptr\n";
  }

  std::unique_ptr<UniquePtr> p3(new UniquePtr());
  if (p3 != nullptr) {
    std::cout << "p3 != nullptr\n";
  }
  UniquePtr *up_ptr = p3.release();
  if (p3 == nullptr) {
    std::cout << "p3 = nullptr\n";
  }
  std::cout << "up_ptr = " << up_ptr << "\n";
  return 0;
}
