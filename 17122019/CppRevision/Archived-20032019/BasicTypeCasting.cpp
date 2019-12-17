#include <iostream>

using namespace std;

class Dummy {
  int i;
};

class Addition {
  int x, y;

public:
  Addition(int x, int y) : x(x), y(y) {}
  int result() { return x + y; }
};

int main(int argc, char *argv[]) {
  Dummy dummy;
  Addition *pAdd;
  pAdd = (Addition *)(&dummy);
  cout << pAdd->result();

  return 0;
}
