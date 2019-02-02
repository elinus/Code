#include <DecoyDuck.h>

DecoyDuck::DecoyDuck() {
  quackBehaviour = new MuteQuack();
  flyBehaviour = new FlyNoWay();
}

DecoyDuck::~DecoyDuck() {
  delete quackBehaviour;
  delete flyBehaviour;
}

void DecoyDuck::display() { std::cout << "I'm a decoy duck" << std::endl; }
