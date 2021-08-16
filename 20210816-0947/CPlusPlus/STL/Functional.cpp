#include <functional>
#include <iostream>

using namespace std::placeholders;

double Divide(double x, double y) { return x / y; }

int main(int argc, char const *argv[]) {
  std::function<double(double, double)> div1 = std::bind(Divide, _1, _2);
  std::function<double(double)> div2 = std::bind(Divide, 2000, _1);
  std::cout << ((Divide(2000, 10) == div1(2000, 10)) == div2(10)) << std::endl;
  return 0;
}
