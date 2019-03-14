#include <iostream>

using namespace std;

class A {};
class B {};

int main(int argc, char *argv[]) {
  A *a = new A;
  B *b = reinterpret_cast<B *>(a);
  return 0;
}
