#include <State/GumballMachine.h>
#include <iostream>

int main(int argc, char *argv[])
{
    auto *gumballMachine = new GumballMachine(2);

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->refill(5);
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();

    std::cout << gumballMachine->toString() << std::endl;

    return 0;
}
