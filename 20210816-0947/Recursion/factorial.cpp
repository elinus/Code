#include <iostream>

using namespace std;

int factorial(int n) {
  if (n <= 0)
    return 1;
  return factorial(n - 1) * n;
}

int main() {
  cout << "factorial recur(5) = " << factorial(5) << endl;
  int fact_ = 1;
  for (int i = 1; i <= 5; i++) {
    fact_ *= i;
  }
  cout << "factorial iter(5) = " << fact_ << endl;
  return 0;
}