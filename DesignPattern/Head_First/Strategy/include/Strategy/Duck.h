#ifndef __DUCK_H__
#define __DUCK_H__

#include <iostream>
#include <Strategy/FlyBehaviour.h>
#include <Strategy/QuackBehaviour.h>

class Duck {
    public:
        Duck();
        virtual void display() = 0;
        void performFly();
        void performQuack();
        void swim();
        void setFlyBehaviour(FlyBehaviour *fb);
        void setQuackBehaviour(QuackBehaviour *qb);
    protected:
        FlyBehaviour *flyBehaviour;
        QuackBehaviour *quackBehaviour;
};

#endif
