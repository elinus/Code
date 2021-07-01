#include <iostream>

int reverse(int A) {
  bool neg = false;
  if (A < 0) {
    neg = true;
    A *= (-1);
  }
  long long res = 0;
  while (A) {
    res = res * 10 + A % 10;
    if (res > INT_MAX || res < INT_MIN)
      return 0;
    A = A / 10;
  }
  return neg ? (-1) * res : res;
}
