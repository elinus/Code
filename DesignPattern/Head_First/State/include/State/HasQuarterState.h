#ifndef __HAS_QUARTER_STATE_H__
#define __HAS_QUARTER_STATE_H__

#include "State.h"
#include "GumballMachine.h"
#include <iostream>
#include <string>

class HasQuarterState : public State {
    public:
        HasQuarterState(GumballMachine *gumballMachine);
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

#endif // !__HAS_QUARTER_STATE_H__

