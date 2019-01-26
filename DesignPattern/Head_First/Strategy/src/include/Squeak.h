#ifndef __SQUEAK_H__
#define __SQUEAK_H__

#include <iostream>
#include <QuackBehaviour.h>

class Squeak : public QuackBehaviour {
    public:
        Squeak();
        virtual ~Squeak();
        void quack();
};

#endif
