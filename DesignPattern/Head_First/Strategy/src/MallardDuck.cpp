#include <Strategy/MallardDuck.h>

MallardDuck::MallardDuck()
{
    flyBehaviour = new FlyWithWings();
}

void MallardDuck::display()
{
    std::cout << "I'm a real Mallard duck" << std::endl;
}
