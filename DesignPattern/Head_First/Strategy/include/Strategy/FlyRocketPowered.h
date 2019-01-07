#ifndef __FLY_ROCKET_POWERED__
#define __FLY_ROCKET_POWERED__

#include <iostream>
#include <Strategy/FlyBehaviour.h>

class FlyRocketPowered : public FlyBehaviour {
    public:
        void fly();
};

#endif
