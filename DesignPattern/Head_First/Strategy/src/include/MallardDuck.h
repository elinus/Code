#ifndef __MALLARD_DUCK__
#define __MALLARD_DUCK__

#include <iostream>
#include <Duck.h>
#include <FlyWithWings.h>
#include <Quack.h>

class MallardDuck : public Duck {
    public:
        MallardDuck();
        void display();
};

#endif
