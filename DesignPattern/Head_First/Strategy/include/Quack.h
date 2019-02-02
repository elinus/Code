#ifndef __QUACK_H__
#define __QUACK_H__

#include <iostream>
#include <QuackBehaviour.h>

class Quack : public QuackBehaviour {
    public:
        Quack();
        ~Quack() override;
        void quack() override;
};

#endif
