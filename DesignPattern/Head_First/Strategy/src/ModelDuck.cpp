#include <Strategy/ModelDuck.h>

ModelDuck::ModelDuck()
{
    quackBehaviour = new Quack();
    flyBehaviour = new FlyNoWay();
}

void ModelDuck::display()
{
    std::cout << "I'm a model duck" << std::endl;
}
