#include <State/SoldState.h>

SoldState::SoldState(GumballMachine * gumballMachine)
{
    this->gumballMachine = gumballMachine;
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank" << std::endl;
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
}

void SoldState::despense()
{
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() > 0) {
        gumballMachine->setState(gumballMachine->getNoQuarterState());
    } else {
        std::cout << "Oops, out of gumballs!" << std::endl;
        gumballMachine->setState(gumballMachine->getSoldOutState());
    }
}

void SoldState::refill()
{
}

std::string SoldState::toString()
{
    return "dispensing a gumball";
}
