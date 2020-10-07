// terminate called after throwing an instance of 'int'

#include <iostream>

using namespace std;

class Test {
public:
  Test() { cout << "Constructor" << endl; }
  ~Test() {
    cout << "Destructor" << endl;
    throw 1;
  }
};

int main(int argc, char *argv[]) {
  try {
    Test obj;
    throw 2;
  } catch (...) {
    cout << "Main exception caught!" << endl;
  }
  return 0;
}
