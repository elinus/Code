#include <any>
#include <iostream>
#include <vector>

using namespace std;
struct MyClass {};

int main() {
  std::vector<std::any> anyVec{true, 2017, std::string("test"), 3.14,
                               MyClass()};
  std::cout << std::any_cast<bool>(anyVec[0]) << endl; // true
  int myInt = std::any_cast<int>(anyVec[1]);
  std::cout << myInt << std::endl << endl; // 2017

  std::cout << anyVec[0].type().name() << endl; // b
  std::cout << anyVec[1].type().name();         // i

  return 0;
}