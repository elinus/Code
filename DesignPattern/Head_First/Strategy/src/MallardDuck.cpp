#include <MallardDuck.h>

MallardDuck::MallardDuck() {
  quackBehaviour = new Quack();
  flyBehaviour = new FlyWithWings();
}

MallardDuck::~MallardDuck() {
  delete quackBehaviour;
  delete flyBehaviour;
}

void MallardDuck::display() {
  std::cout << "I'm a real Mallard duck" << std::endl;
}
