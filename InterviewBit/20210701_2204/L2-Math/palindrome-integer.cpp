int isPalindrome(int A) {
  if (A < 0)
    return false;
  int x = A;
  long long res = 0;
  while (x) {
    res = res * 10 + x % 10;
    x = x / 10;
  }
  return res == A;
}
