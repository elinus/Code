#ifndef __WILD_TURKEY_H__
#define __WILD_TURKEY_H__

#include <Adapter/Turkey.h>
#include <iostream>

class WildTurkey : public Turkey {
    public:
        void gobble();
        void fly();
};

#endif
