#ifndef __SQUEAK_H__
#define __SQUEAK_H__

#include <iostream>
#include <Strategy/QuackBehaviour.h>

class Squeak : public QuackBehaviour {
    public:
        void quack();
};

#endif
