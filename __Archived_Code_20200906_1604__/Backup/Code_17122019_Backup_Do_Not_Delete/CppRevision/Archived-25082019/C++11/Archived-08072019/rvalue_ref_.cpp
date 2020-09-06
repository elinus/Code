#include <iostream>

int getValue() { return 14; }

int main(int argc, char *argv[]) {
  int &&rvalueRef = getValue();
  const int &lvalueRef_ = getValue();

  int x = 20;
  int &lvalueRef = x;

  int &&rvalueRefx = (x + 1);

  return 0;
}
