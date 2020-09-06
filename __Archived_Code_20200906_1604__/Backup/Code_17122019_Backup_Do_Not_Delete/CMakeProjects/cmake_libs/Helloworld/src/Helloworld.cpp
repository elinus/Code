#include <Helloworld/Helloworld.h>

void Helloworld::sayHello(int n) {
  for (int i = 0; i < n; i++) {
    std::cout << "Hello world !! { " << i << " }" << std::endl;
  }
}
