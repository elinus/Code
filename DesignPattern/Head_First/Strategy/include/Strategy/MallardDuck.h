#ifndef __MALLARD_DUCK__
#define __MALLARD_DUCK__

#include <iostream>
#include <Strategy/Duck.h>

class MallardDuck : public Duck {
    public:
        MallardDuck();
        void display();
};

#endif
