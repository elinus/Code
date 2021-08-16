#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int A) {
  for (auto i = 2; i * i <= A; ++i)
    if (A % i == 0)
      return false;
  return true;
}

vector<int> primesum(int A) {
  vector<int> res;
  if (A % 2 != 0)
    return res;

  for (auto j = 2; j <= A / 2; ++j) {
    auto diff = A - j;
    if (isPrime(j) && isPrime(diff)) {
      res.emplace_back(j);
      res.emplace_back(diff);
      break;
    }
  }
  return res;
}
