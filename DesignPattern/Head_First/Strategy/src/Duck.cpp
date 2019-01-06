#include <Strategy/Duck.h>

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
