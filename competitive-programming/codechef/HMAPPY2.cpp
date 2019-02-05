#include <bits/stdc++.h>
#define ulli unsigned long long int

using namespace std;

ulli gcd(ulli a, ulli b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ulli lcm(ulli a, ulli b) { return (a * b) / gcd(a, b); }

int main(int argc, char *argv[]) {
  int T;
  ulli N, A, B, K;
  std::cin >> T;
  while (T--) {
    cin >> N >> A >> B >> K;
    ulli ldivA = (N % A == 0) ? N : N - N % A;
    ulli countA = (ldivA - A) / A + 1;
    ulli ldivB = (N % B == 0) ? N : N - N % B;
    ulli countB = (ldivB - B) / B + 1;

    ulli lcm_ = lcm(A, B);
    ulli ldivAB = (N % lcm_ == 0) ? N : N - N % lcm_;
    ulli countAB = (ldivAB - lcm_) / lcm_ + 1;
    countA -= countAB;
    countB -= countAB;
    if (countA + countB >= K) {
      cout << "Win" << endl;
    } else {
      cout << "Lose" << endl;
    }
  }
  return 0;
}
