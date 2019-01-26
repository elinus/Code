#ifndef __RUBBER_DUCK__
#define __RUBBER_DUCK__

#include <iostream>
#include <Duck.h>
#include <FlyNoWay.h>
#include <Squeak.h>

class RubberDuck : public Duck {
    public:
        RubberDuck();
        ~RubberDuck();
        void display();
};

#endif
