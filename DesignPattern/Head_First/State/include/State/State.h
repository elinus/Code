#ifndef __STATE_H__
#define __STATE_H__

#include <string>

class State {
public:
  virtual void insertQuarter() = 0;
  virtual void ejectQuarter() = 0;
  virtual void turnCrank() = 0;
  virtual void despense() = 0;
  virtual void refill() = 0;
  virtual std::string toString() = 0;
};

#endif
