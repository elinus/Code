#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

struct StringHashBySize {
public:
  size_t operator()(const std::string &str) const {
    int size_ = str.length();
    return std::hash<int>()(size_);
  }
};

struct StringEqualBySize {
public:
  bool operator()(const std::string &s1, const std::string &s2) const {
    if (s1.length() == s2.length())
      return true;
    return false;
  }
};

int main(int argc, char *argv[]) {
  std::unordered_set<std::string, StringHashBySize, StringEqualBySize> uset;
  uset.insert("first");
  uset.insert("second");
  uset.insert("third");

  auto it = uset.begin();
  for (it = uset.begin(); it != uset.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  return 0;
}
