#ifndef __TEA_H__
#define __TEA_H__

#include <TemplateMethod/CaffeineBeverage.h>
#include <string>

class Tea : public CaffeineBeverage {
    public:
        void brew();
        void addCondiments();
        bool customerWantsCondiments();
    private:
        std::string getUserInput();
};

#endif
