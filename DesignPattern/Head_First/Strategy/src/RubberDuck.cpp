#include <Strategy/RubberDuck.h>

RubberDuck::RubberDuck()
{
    quackBehaviour = new Squeak();
    flyBehaviour = new FlyNoWay();
}

void RubberDuck::display()
{
    std::cout << "I'm a rubber duck" << std::endl;
}
