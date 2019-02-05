#include <iostream>
#include <string>
#include <unordered_set>

int main(int argc, char *argv[]) {
  std::unordered_set<std::string> uset;
  uset.insert("First");
  uset.insert("Second");
  uset.insert("third");

  for (std::string elem : uset) {
    std::cout << elem << std::endl;
  }
  return 0;
}
