#ifndef __SOLD_STATE_H__
#define __SOLD_STATE_H__

#include "GumballMachine.h"
#include "State.h"
#include <iostream>
#include <string>

class SoldState : public State {
    public:
        SoldState(GumballMachine *gumballMachine);
        virtual void insertQuarter() override;
        virtual void ejectQuarter() override;
        virtual void turnCrank() override;
        virtual void despense() override;
        virtual void refill() override;
        virtual std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__SOLD_STATE_H__
