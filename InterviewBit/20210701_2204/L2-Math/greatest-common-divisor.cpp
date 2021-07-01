int gcd(int A, int B) {
  int dividend = A > B ? A : B;
  int divisor = A > B ? B : A;
  while (divisor != 0) {
    int remainder = dividend % divisor;
    dividend = divisor;
    divisor = remainder;
  }
  return dividend;
}