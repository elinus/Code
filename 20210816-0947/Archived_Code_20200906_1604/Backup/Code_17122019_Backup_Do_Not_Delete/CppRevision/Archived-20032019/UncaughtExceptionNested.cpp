#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    try {
      throw 1;
    } catch (int e) {
      cout << "Int exception." << endl;
      throw;
    }
  } catch (...) {
    cout << "Error occured." << endl;
  }

  return 0;
}
