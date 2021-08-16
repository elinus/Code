#include <iostream>
using namespace std;

int nCr(int n, int r) {
  if (r == 0 || n == r)
    return 1;
  return nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main(int argc, char const *argv[]) {
  int n = 7, r = 3;
  cout << nCr(n, r) << endl;
  return 0;
}
