#include <iostream>

using namespace std;

class A {};

int main(int argc, char *argv[]) {
  const A *a = new A;
  A *ptr = const_cast<A *>(a);
  return 0;
}
