#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
  std::shared_ptr<int> ptr = std::make_shared<int>(14);
  std::cout << "ptr = " << ptr << ", *ptr = " << *ptr << "\n";
  std::weak_ptr<int> weak_ptr(ptr);
  std::shared_ptr<int> p1 = weak_ptr.lock();
  if (p1) {
    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << "\n";
  }
  std::cout << "Ref. count :: " << p1.use_count() << "\n";
  if (weak_ptr.expired() == false) {
    std::cout << "Not expired yet!"
              << "\n";
  }

  return 0;
}
