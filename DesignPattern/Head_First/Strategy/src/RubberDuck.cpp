#include <RubberDuck.h>

RubberDuck::RubberDuck() {
  quackBehaviour = new Squeak();
  flyBehaviour = new FlyNoWay();
}

RubberDuck::~RubberDuck() {
  delete quackBehaviour;
  delete flyBehaviour;
}

void RubberDuck::display() { std::cout << "I'm a rubber duck" << std::endl; }
