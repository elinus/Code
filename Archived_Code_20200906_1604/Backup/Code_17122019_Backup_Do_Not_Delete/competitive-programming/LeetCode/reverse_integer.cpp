#include <iostream>
#include <limits>

int reverse_(int x) {
  int max_ = std::numeric_limits<int>::max();
  int min_ = std::numeric_limits<int>::min();
  int num = 0;
  while (x) {
    long expr = (long)num * 10 + x % 10;
    if (expr > max_ || expr < min_)
      return 0;
    num = (num * 10) + (x % 10);
    x = x / 10;
  }
  return num;
}

class Solution {
public:
  int reverse(int x) {
    if (x < 0) {
      return (-1) * reverse_((-1) * x);
    }

    return reverse_(x);
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  int i = 1534236469;
  std::cout << i << std::endl;
  std::cout << so.reverse(i) << std::endl;
  return 0;
}
