#include <RedheadDuck.h>

RedheadDuck::RedheadDuck() {
  quackBehaviour = new Quack();
  flyBehaviour = new FlyWithWings();
}

RedheadDuck::~RedheadDuck() {
  delete quackBehaviour;
  delete flyBehaviour;
}

void RedheadDuck::display() { std::cout << "I'm a red head duck" << std::endl; }
