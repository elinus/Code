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
        virtual void insertQuarter() override;
        virtual void ejectQuarter() override;
        virtual void turnCrank() override;
        virtual void despense() override;
        virtual void refill() override;
        virtual std::string toString() override;
    private:
        GumballMachine *gumballMachine;
};

#endif // !__HAS_QUARTER_STATE_H__

