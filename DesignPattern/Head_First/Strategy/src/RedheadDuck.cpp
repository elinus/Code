#include <Strategy/RedheadDuck.h>

RedheadDuck::RedheadDuck()
{
    quackBehaviour = new Quack();
    flyBehaviour = new FlyWithWings();
}

void RedheadDuck::display()
{
    std::cout << "I'm a red head duck" << std::endl;
}
