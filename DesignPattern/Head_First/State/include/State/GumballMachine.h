#ifndef __GUMBALL_MACHINE_H__
#define __GUMBALL_MACHINE_H__

#include "State.h"
#include <iostream>
#include <string>

class GumballMachine {
public:
  GumballMachine(int numberGumballs);
  void insertQuarter();
  void ejectQuarter();
  void turnCrank();
  void releaseBall();
  int getCount();
  void refill(int count);
  void setState(State *state);
  State *getState();
  State *getSoldOutState();
  State *getNoQuarterState();
  State *getHasQuarterState();
  State *getSoldState();
  std::string toString();

private:
  State *soldOutState;
  State *noQuarterState;
  State *hasQuarterState;
  State *soldState;
  State *state;
  int count = 0;
};

#endif
