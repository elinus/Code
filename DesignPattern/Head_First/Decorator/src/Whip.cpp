#include <Decorator/Whip.h>

Whip::Whip(Beverage *beverage) { this->beverage = beverage; }

std::string Whip::getDescription() {
  return beverage->getDescription() + ", Whip";
}

double Whip::cost() { return beverage->cost() + 0.10; }
