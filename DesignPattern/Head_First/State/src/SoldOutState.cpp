#include <State/SoldOutState.h>

SoldOutState::SoldOutState(GumballMachine *gumballMachine) {
  this->gumballMachine = gumballMachine;
}

void SoldOutState::insertQuarter() {
  std::cout << "You can't insert a quarter, the machine is sold out"
            << std::endl;
}

void SoldOutState::ejectQuarter() {
  std::cout << "You can't eject, you haven't inserted a quarter yet"
            << std::endl;
}

void SoldOutState::turnCrank() {
  std::cout << "You turned, but there are no gumballs" << std::endl;
}

void SoldOutState::despense() {
  std::cout << "No gumball dispensed" << std::endl;
}

void SoldOutState::refill() {
  gumballMachine->setState(gumballMachine->getNoQuarterState());
}

std::string SoldOutState::toString() { return "sold out"; }
