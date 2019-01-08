#ifndef __CAFFEINE_BEVERAGE_H__
#define __CAFFEINE_BEVERAGE_H__

#include <iostream>

class CaffeineBeverage {
    public:
        virtual void brew() = 0;
        virtual void addCondiments() = 0;
        void boilWater();
        void pourInCup();
        void prepareRecipe();
        virtual bool customerWantsCondiments();
};

#endif
