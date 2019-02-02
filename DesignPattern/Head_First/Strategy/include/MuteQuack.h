#ifndef __MUTEQUACK_H__
#define __MUTEQUACK_H__

#include <iostream>
#include <QuackBehaviour.h>

class MuteQuack : public QuackBehaviour {
    public:
        MuteQuack();
        ~MuteQuack() override;
        void quack() override;
};

#endif
