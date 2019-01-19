#ifndef __NO_QUARTER_STATE_H__
#define __NO_QUARTER_STATE_H__

#include "GumballMachine.h"
#include "State.h"
#include <iostream>
#include <string>

class NoQuarterState : public State {
    public:
        NoQuarterState(GumballMachine *gumballMachine);
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

#endif // !__NO_QUARTER_STATE_H__
