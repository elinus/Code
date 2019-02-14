#include <boost/version.hpp>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Boost version: " << BOOST_VERSION / 100000 << "."
            << BOOST_VERSION / 100 % 1000 << "." << BOOST_VERSION % 100
            << std::endl;
  return 0;
}
