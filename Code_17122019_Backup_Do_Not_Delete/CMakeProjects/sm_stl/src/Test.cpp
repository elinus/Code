#include "Vector.h"
#include <iostream>

int main() {

  sm_stl::Vector<int> x;
  x.push_back(14);
  x.push_back(20);

  sm_stl::Vector<int> y(x);
  sm_stl::Vector<int> z;
  z = x;
  return 0;
}
