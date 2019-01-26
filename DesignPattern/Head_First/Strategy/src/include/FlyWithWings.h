#ifndef __FLY_WITH_WINGS__
#define __FLY_WITH_WINGS__

#include <iostream>
#include <FlyBehaviour.h>

class FlyWithWings : public FlyBehaviour {
    public:
        FlyWithWings();
        virtual ~FlyWithWings();
        void fly();
};

#endif
