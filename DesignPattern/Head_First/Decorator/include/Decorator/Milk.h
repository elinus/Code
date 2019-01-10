#ifndef __MILK_H__
#define __MILK_H__

#include <Decorator/CondimentDecorator.h>

class Milk : public CondimentDecorator {
    public:
        Milk(Beverage *beverage);
        std::string getDescription();
        double cost();
    private:
        Beverage *beverage;
};

#endif
