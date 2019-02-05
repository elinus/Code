#include <exception>
#include <iostream>

using namespace std;

class DerivedException : public exception {
public:
  virtual const char *what() const throw() { return "{ DerivedException }"; }
} derEx;

int main(int argc, char *argv[]) {
  try {
    throw derEx;
  } catch (exception &e) {
    cout << "Caught Exception: " << e.what() << endl;
  }
  return 0;
}
