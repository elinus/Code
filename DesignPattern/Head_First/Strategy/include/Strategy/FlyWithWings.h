#ifndef __FLY_WITH_WINGS__
#define __FLY_WITH_WINGS__

#include <iostream>
#include <Strategy/FlyBehaviour.h>

class FlyWithWings : public FlyBehaviour {
    public:
        void fly();
};

#endif
