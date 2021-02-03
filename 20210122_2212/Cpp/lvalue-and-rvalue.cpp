#include <iostream>

void fun(const int &lref) // lvalue arguments will select this function
{
  std::cout << "lvalue reference to const\n";
}

void fun(int &&rref) // rvalue arguments will select this function
{
  std::cout << "rvalue reference\n";
}

int main(int argc, char const *argv[]) {
  /* lvalue reference */
  int x = 5;
  int &lref = x;
  std::cout << "lref = " << lref << ",  x = " << x << "\n";
  // lvalue reference can ony be initialized with modifiable lvalues

  fun(5);
  fun(x);
  return 0;
}
