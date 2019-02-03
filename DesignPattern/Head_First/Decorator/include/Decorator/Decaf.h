#ifndef __DECAF_H__
#define __DECAF_H__

#include <Decorator/Beverage.h>

class Decaf : public Beverage {
    public:
        Decaf();
        double cost() override;
};

#endif
