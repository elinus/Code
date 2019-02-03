#ifndef __SOLD_STATE_H__
#define __SOLD_STATE_H__

#include "GumballMachine.h"
#include "State.h"
#include <iostream>
#include <string>

class SoldState : public State {
    public:
        SoldState(GumballMachine *gumballMachine);
        void insertQuarter() override;
        void ejectQuarter() override;
        void turnCrank() override;
        void despense() override;
        void refill() override;
        std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__SOLD_STATE_H__
