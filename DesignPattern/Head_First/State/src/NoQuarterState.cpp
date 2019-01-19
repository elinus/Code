#include <State/NoQuarterState.h>

NoQuarterState::NoQuarterState(GumballMachine * gumballMachine)
{
    this->gumballMachine = gumballMachine;
}

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter" << std::endl;
    gumballMachine->setState(gumballMachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter" << std::endl;
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there's no quarter" << std::endl;
}

void NoQuarterState::despense()
{
    std::cout << "You need to pay first" << std::endl;
}

void NoQuarterState::refill()
{
}

std::string NoQuarterState::toString()
{
    return "waiting for quarter";
}
