#include <iostream>
#include <vector>

class Container {
private:
  int *data;

public:
  Container() {
    data = new int[20];
    std::cout << "Constructor\n";
  }

  ~Container() {
    if (data) {
      delete[] data;
      data = nullptr;
    }
  }

  Container(const Container &other) {
    data = new int[20];
    for (int i = 0; i < 20; i++) {
      data[i] = other.data[i];
    }
    std::cout << "Copy COnstructor\n";
  }

  Container &operator=(const Container &other) {
    if (this != &other) {
      data = new int[20];
      for (int i = 0; i < 20; i++) {
        data[i] = other.data[i];
      }
    }
    return *this;
  }

  // move constructor
  Container(Container &&other) {
    data = other.data;
    other.data = nullptr;
    std::cout << "Move COnstructor\n";
  }

  Container &operator=(Container &&other) {
    if (this != &other) {
      data = other.data;
      other.data = nullptr;
    }
    return *this;
  }
};

Container getContainer() {
  std::cout << "getContainer\n";
  Container obj;
  return obj;
}

int main(int argc, char *argv[]) {
  std::vector<Container> vec;
  vec.push_back(getContainer());
  return 0;
}
