#include <Strategy/DecoyDuck.h>

DecoyDuck::DecoyDuck()
{
    quackBehaviour = new MuteQuack();
    flyBehaviour = new FlyNoWay();
}

void DecoyDuck::display()
{
    std::cout << "I'm a decoy duck" << std::endl;
}
