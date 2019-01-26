#include <Duck.h>

Duck::Duck()
{}

void Duck::swim()
{
    std::cout << "All ducks float, even decoys!" << std::endl;
}

void Duck::performFly()
{
    flyBehaviour->fly();
}

void Duck::performQuack()
{
    quackBehaviour->quack();
}

void Duck::setFlyBehaviour(FlyBehaviour *fb)
{
    flyBehaviour = fb;
}

void Duck::setQuackBehaviour(QuackBehaviour *qb)
{
    quackBehaviour = qb;
}
