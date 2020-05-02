#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
  pair<char, int> test;
  test.first = 'S';
  test.second = 14;
  cout << test.first << ", " << test.second << "\n";

  // swap
  pair<int, char> p1 = make_pair(20, 'A');
  pair<int, char> p2 = make_pair(14, 'S');
  cout << "before swap:" << endl;
  cout << &p1 << ":(" << p1.first << ", " << p1.second << ")\n";
  cout << &p2 << ":(" << p2.first << ", " << p2.second << ")\n";

  p1.swap(p2);

  cout << "after swap:" << endl;
  cout << &p1 << ":(" << p1.first << ", " << p1.second << ")\n";
  cout << &p2 << ":(" << p2.first << ", " << p2.second << ")\n";
  return 0;
}
