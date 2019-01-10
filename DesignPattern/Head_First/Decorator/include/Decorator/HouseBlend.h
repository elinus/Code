#ifndef __HOUSE_BLEND_H__
#define __HOUSE_BLEND_H__

#include <Decorator/Beverage.h>

class HouseBlend : public Beverage {
    public:
        HouseBlend();
        double cost();
};

#endif
