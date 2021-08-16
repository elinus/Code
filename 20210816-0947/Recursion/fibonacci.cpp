#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibs(int n, vector<int> &dp) {
  if (n <= 1) {
    dp[n] = n;
    return n;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  dp[n] = fibs(n - 1, dp) + fibs(n - 2, dp);
  return dp[n];
}

int main() {
  int n = 10;
  cout << "fibonacci recur(7) = " << fibonacci(n) << endl;
  int first = 0, second = 1;
  for (int i = 2; i <= n; i++) {
    int tmp = first + second;
    first = second;
    second = tmp;
  }
  cout << "fibonacci iter(7) = " << second << endl;

  vector<int> dp(n + 1, -1);
  cout << "fibonacci recur(7) dp = " << fibs(n, dp) << endl;
  return 0;
}