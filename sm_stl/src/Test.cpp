#include "Vector.h"
#include <iostream>

int main() {

  sm_stl::Vector<int> x;
  sm_stl::Vector<int> y(x);
  sm_stl::Vector<int> z;
  z = x;
  return 0;
}
