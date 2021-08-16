#include <iostream>
using namespace std;

// e^x = 1 + x / 1 + x^2 / 2! + x^3 / 3! + ... + x ^ n / n!

double taylor_series(int x, int n) {
  static int p = 1, f = 1;
  if (n == 0)
    return 1;

  int r = taylor_series(x, n - 1);
  p *= x;
  f *= n;
  return r + (double)p / f;
}

double e(int x, int n) {
  static double s;
  if (n == 0)
    return s;
  s = 1 + x * s / n;
  return e(x, n - 1);
}

int main(int argc, char const *argv[]) {
  // iter
  double e_x = 1;
  int p = 1;
  int f = 1;
  int x = 1;
  int n = 4;
  for (int i = 1; i <= n; i++) {
    p *= x;
    f *= i;
    double r = (double)p / f;
    cout << r << endl;
    e_x += r;
  }
  cout << "e_x = " << e_x << endl;
  cout << "e_x(x, 4) = " << taylor_series(x, n) << endl;
  cout << "e_x(x, 4) = " << e(x, n) << endl;
  return 0;
}
