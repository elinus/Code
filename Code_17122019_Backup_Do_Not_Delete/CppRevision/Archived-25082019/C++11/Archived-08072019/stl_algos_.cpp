#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<std::string> vec = {"Hi",     "Hello", "test",  "first",
                                  "second", "third", "fourth"};

  bool res1 = std::all_of(vec.begin(), vec.end(), [](const std::string &str) {
    return str.size() > 0 && ::isupper(str[0]);
  });
  std::cout << res1 << "\n";

  bool res2 = std::any_of(vec.begin(), vec.end(), [](const std::string &str) {
    return str.size() > 0 && ::isupper(str[0]);
  });
  std::cout << res2 << "\n";
  return 0;
}
