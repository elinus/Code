#include <ModelDuck.h>

ModelDuck::ModelDuck()
{
    quackBehaviour = new Quack();
    flyBehaviour = new FlyNoWay();
}

ModelDuck::~ModelDuck()
{
    delete quackBehaviour;
    delete flyBehaviour;
}

void ModelDuck::display()
{
    std::cout << "I'm a model duck" << std::endl;
}
