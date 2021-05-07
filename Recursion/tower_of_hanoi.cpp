#include <iostream>

using namespace std;

void toh(int n, int src, int intr, int dest) {
  if (n > 0) {
    toh(n - 1, src, dest, intr);
    cout << "Move : " << static_cast<char>(src) << " -> "
         << static_cast<char>(dest) << endl;
    toh(n - 1, intr, src, dest);
  }
}

int main(int argc, char const *argv[]) {
  toh(3, 'A', 'B', 'C');
  return 0;
}
