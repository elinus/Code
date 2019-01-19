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
        virtual void insertQuarter() override;
        virtual void ejectQuarter() override;
        virtual void turnCrank() override;
        virtual void despense() override;
        virtual void refill() override;
        virtual std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__SOLD_OUT_STATE_H__

