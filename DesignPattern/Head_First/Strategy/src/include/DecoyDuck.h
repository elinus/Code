#ifndef __DECOY_DUCK__
#define __DECOY_DUCK__

#include <iostream>
#include <Duck.h>
#include <FlyNoWay.h>
#include <MuteQuack.h>

class DecoyDuck : public Duck {
    public:
        DecoyDuck();
        ~DecoyDuck();
        void display();
};

#endif
