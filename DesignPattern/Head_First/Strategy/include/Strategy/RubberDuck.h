#ifndef __RUBBER_DUCK__
#define __RUBBER_DUCK__

#include <iostream>
#include <Strategy/Duck.h>
#include <Strategy/FlyNoWay.h>
#include <Strategy/Squeak.h>

class RubberDuck : public Duck {
    public:
        RubberDuck();
        void display();
};

#endif
