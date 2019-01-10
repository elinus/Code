#ifndef __CONDIMENT_DECORATOR_H__
#define __CONDIMENT_DECORATOR_H__

#include <Decorator/Beverage.h>

class CondimentDecorator : public Beverage {
    public:
        virtual std::string getDescription() = 0;
};

#endif
