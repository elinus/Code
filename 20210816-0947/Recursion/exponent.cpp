#include <iostream>

using namespace std;

int exp(int m, int n) {
  if (n <= 0)
    return 1;
  return m * exp(m, n - 1);
}

int main() {
  cout << "exp recur(2, 5) = " << exp(2, 5) << endl;
  int exp_ = 1;
  for (int i = 1; i <= 5; i++) {
    exp_ *= 2;
  }
  cout << "exp iter(2, 5) = " << exp_ << endl;

  return 0;
}