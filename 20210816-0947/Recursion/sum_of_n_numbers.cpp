#include <iostream>

using namespace std;

int sum(int n) {
  if (n <= 0)
    return 0;
  return sum(n - 1) + n;
}

int main() {
  cout << "sum recur(5) = " << sum(5) << endl;
  int sum_ = 0;
  for (int i = 1; i <= 5; i++) {
    sum_ += i;
  }
  cout << "sum iter(5) = " << sum_ << endl;
  cout << "sum(5) = " << (5 * (5 + 1) / 2) << endl;
  return 0;
}