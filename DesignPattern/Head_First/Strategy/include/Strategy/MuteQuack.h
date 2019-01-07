#ifndef __MUTEQUACK_H__
#define __MUTEQUACK_H__

#include <iostream>
#include <Strategy/QuackBehaviour.h>

class MuteQuack : public QuackBehaviour {
    public:
        void quack();
};

#endif
