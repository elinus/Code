#include <State/HasQuarterState.h>

HasQuarterState::HasQuarterState(GumballMachine * gumballMachine)
{
    this->gumballMachine = gumballMachine;
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter" << std::endl;
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned" << std::endl;
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "You turned..." << std::endl;
    gumballMachine->setState(gumballMachine->getSoldState());
}

void HasQuarterState::despense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void HasQuarterState::refill()
{
}

std::string HasQuarterState::toString()
{
    return "waiting for turn of crank";
}
