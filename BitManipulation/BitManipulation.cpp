#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int s = 14;
  cout << "s = " << bitset<8 * sizeof(int)>(s) << endl;

  int a = 20;
  cout << "a = " << bitset<8 * sizeof(int)>(a) << endl;

  // get
  bool out = (a & (1 << 14)) != 0;
  cout << "a(14) = " << out << endl;
  out = (a & (1 << 4)) != 0;
  cout << "a(4) = " << out << endl;

  // set
  a |= (1 << 14);
  cout << "a(set=14) = " << bitset<8 * sizeof(int)>(a)  << "\nNew(a) = " << a << endl;
  return 0;
}
