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
        void insertQuarter() override;
        void ejectQuarter() override;
        void turnCrank() override;
        void despense() override;
        void refill() override;
        std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__NO_QUARTER_STATE_H__
