#include <State/GumballMachine.h>
#include <State/State.h>
#include <State/HasQuarterState.h>
#include <State/NoQuarterState.h>
#include <State/SoldOutState.h>
#include <State/SoldState.h>

GumballMachine::GumballMachine(int numberGumballs)
{
    soldOutState = new SoldOutState(this);
    noQuarterState = new NoQuarterState(this);
    hasQuarterState = new HasQuarterState(this);
    soldState = new SoldState(this);
    this->count = numberGumballs;
    if (numberGumballs > 0) {
        state = noQuarterState;
    } else {
        state = soldOutState;
    }
}

void GumballMachine::insertQuarter()
{
    state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    state->turnCrank();
    state->despense();
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
    if (count != 0) {
        count = count - 1;
    }
}

int GumballMachine::getCount()
{
    return count;
}

void GumballMachine::refill(int count)
{
    this->count += count;
    std::cout << "The gumball machine was just refilled; it's new count is: " << this->count << std::endl;
    state->refill();
}

void GumballMachine::setState(State * state)
{
    this->state = state;
}

State * GumballMachine::getState()
{
    return state;
}

State * GumballMachine::getSoldOutState()
{
    return soldOutState;
}

State * GumballMachine::getNoQuarterState()
{
    return noQuarterState;
}

State * GumballMachine::getHasQuarterState()
{
    return hasQuarterState;
}

State * GumballMachine::getSoldState()
{
    return soldState;
}

std::string GumballMachine::toString()
{
    std::string result;
    result.append("\nMighty Gumball, Inc.");
    result.append("\nC++-enabled Standing Gumball Model #2019");
    result.append("\nInventory: ");
    result.append(std::to_string(this->count));
    result.append(" gumball");
    if (this->count != 1) {
        result.append("s");
    }
    result.append("\n");
    result.append("Machine is ");
    result.append(state->toString());
    result.append("name");
    return result;
}
