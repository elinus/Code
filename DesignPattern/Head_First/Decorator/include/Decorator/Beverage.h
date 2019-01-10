#ifndef __BEVERAGE_H__
#define __BEVERAGE_H__

#include <string>

class Beverage {
    public:
        std::string description = "Unknown Beverage";
        virtual std::string getDescription();
        virtual double cost() = 0;
};

#endif
