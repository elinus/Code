#ifndef __FLY_NO_WAY__
#define __FLY_NO_WAY__

#include <iostream>
#include <FlyBehaviour.h>

class FlyNoWay : public FlyBehaviour {
    public:
        FlyNoWay();
        ~FlyNoWay() override;
        void fly() override;
};

#endif
