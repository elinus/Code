#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*Write the class AddElements here*/
template <typename T> class AddElements {
public:
  AddElements(T data) : data(data) {}
  T add(T data) { return this->data + data; }
  T concatenate(T data) { return this->data + data; }

private:
  T data;
};

int main() {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "float") {
      double element1, element2;
      cin >> element1 >> element2;
      AddElements<double> myfloat(element1);
      cout << myfloat.add(element2) << endl;
    } else if (type == "int") {
      int element1, element2;
      cin >> element1 >> element2;
      AddElements<int> myint(element1);
      cout << myint.add(element2) << endl;
    } else if (type == "string") {
      string element1, element2;
      cin >> element1 >> element2;
      AddElements<string> mystring(element1);
      cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
