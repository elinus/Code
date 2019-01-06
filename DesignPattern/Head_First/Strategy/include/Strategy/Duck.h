#ifndef __DUCK_H__
#define __DUCK_H__

#include <Strategy/FlyWithWings.h>

class Duck {
    public:
        Duck();
        virtual void display() = 0;
        void performFly();
        void swim();
    protected:
        FlyBehaviour *flyBehaviour;
};

#endif
