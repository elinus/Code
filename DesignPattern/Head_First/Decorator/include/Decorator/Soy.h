#ifndef __SOY_H__
#define __SOY_H__

#include <Decorator/CondimentDecorator.h>

class Soy : public CondimentDecorator {
    public:
        Soy(Beverage *beverage);
        std::string getDescription();
        double cost();
    private:
        Beverage *beverage;
};

#endif
