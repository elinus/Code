#ifndef __COFFEE_H__
#define __COFFEE_H__

#include <TemplateMethod/CaffeineBeverage.h>
#include <string>

class Coffee : public CaffeineBeverage {
    public:
        void brew();
        void addCondiments();
        bool customerWantsCondiments();
    private:
        std::string getUserInput();
};

#endif
