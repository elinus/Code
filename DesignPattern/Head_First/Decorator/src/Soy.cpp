#include <Decorator/Soy.h>

Soy::Soy(Beverage *beverage)
{
    this->beverage = beverage;
}

std::string Soy::getDescription()
{
    return beverage->getDescription() + ", Soy";
}

double Soy::cost()
{
    return beverage->cost() + 0.15;
}
