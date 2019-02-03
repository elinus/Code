#ifndef __DARK_ROAST_H__
#define __DARK_ROAST_H__

#include <Decorator/Beverage.h>

class DarkRoast : public Beverage {
    public:
        DarkRoast();
        double cost() override;
};

#endif
