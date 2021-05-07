#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, int> m1;
  for (int i = 0; i < 5; i++) {
    m1[i] = i;
  }
  for (auto it = m1.begin(); it != m1.end(); ++it) {
    cout << it->first << " ";
  }
  cout << endl;

  map<int, int, greater<int>> m2;
  for (int i = 0; i < 5; i++) {
    m2[i] = i;
  }
  for (auto it = m2.begin(); it != m2.end(); ++it) {
    cout << it->first << " ";
  }
  cout << endl;
}