#ifndef __REDHEAD_DUCK__
#define __REDHEAD_DUCK__

#include <iostream>
#include <Strategy/Duck.h>
#include <Strategy/FlyWithWings.h>
#include <Strategy/Quack.h>

class RedheadDuck : public Duck {
    public:
        RedheadDuck();
        void display();
};

#endif
