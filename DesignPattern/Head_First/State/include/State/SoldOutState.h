#ifndef __SOLD_OUT_STATE_H__
#define __SOLD_OUT_STATE_H__

#include "GumballMachine.h"
#include "State.h"
#include <iostream>
#include <string>

class SoldOutState : public State {
    public:
        SoldOutState(GumballMachine *gumballMachine);
        // Inherited via State
        void insertQuarter() override;
        void ejectQuarter() override;
        void turnCrank() override;
        void despense() override;
        void refill() override;
        std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__SOLD_OUT_STATE_H__

