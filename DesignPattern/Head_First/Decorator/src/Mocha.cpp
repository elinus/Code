#include <Decorator/Mocha.h>

Mocha::Mocha(Beverage *beverage)
{
    this->beverage = beverage;
}

std::string Mocha::getDescription()
{
    return beverage->getDescription() + ", Mocha";
}

double Mocha::cost()
{
    return beverage->cost() + 0.20;
}
