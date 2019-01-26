#ifndef __QUACK_H__
#define __QUACK_H__

#include <iostream>
#include <QuackBehaviour.h>

class Quack : public QuackBehaviour {
    public:
        Quack();
        virtual ~Quack();
        void quack();
};

#endif
