#ifndef __DECOY_DUCK__
#define __DECOY_DUCK__

#include <iostream>
#include <Strategy/Duck.h>
#include <Strategy/FlyNoWay.h>
#include <Strategy/MuteQuack.h>

class DecoyDuck : public Duck {
    public:
        DecoyDuck();
        void display();
};

#endif
