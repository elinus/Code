#ifndef __QUACK_H__
#define __QUACK_H__

#include <iostream>
#include <Strategy/QuackBehaviour.h>

class Quack : public QuackBehaviour {
    public:
        void quack();
};

#endif
