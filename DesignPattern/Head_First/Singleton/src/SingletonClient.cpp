#include <Singleton/Singleton.h>
#include <iostream>

int main(int argc, char *argv[]) {
  Singleton *singleton = Singleton::getInstance();
  std::cout << singleton->getDescription() << std::endl;
  return 0;
}
