#ifndef __MOCHA_H__
#define __MOCHA_H__

#include <Decorator/CondimentDecorator.h>

class Mocha : public CondimentDecorator {
    public:
        Mocha(Beverage *beverage);
        std::string getDescription() override;
        double cost() override;
    private:
        Beverage *beverage;
};

#endif
