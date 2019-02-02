#ifndef __FLY_ROCKET_POWERED__
#define __FLY_ROCKET_POWERED__

#include <iostream>
#include <FlyBehaviour.h>

class FlyRocketPowered : public FlyBehaviour {
    public:
        FlyRocketPowered();
        ~FlyRocketPowered() override;
        void fly() override;
};

#endif
