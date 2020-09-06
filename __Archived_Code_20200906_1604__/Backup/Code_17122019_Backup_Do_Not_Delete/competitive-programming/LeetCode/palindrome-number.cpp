#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(int x) {
    std::string str(std::to_string(x));

    for (int i = 0, j = str.size() - 1; j > i; i++, j--) {
      if (str[i] != str[j])
        return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  std::cout << so.isPalindrome(121) << std::endl;
  return 0;
}
