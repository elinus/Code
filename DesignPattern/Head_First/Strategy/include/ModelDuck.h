#ifndef __MODEL_DUCK__
#define __MODEL_DUCK__

#include <iostream>
#include <Duck.h>
#include <FlyNoWay.h>
#include <Quack.h>

class ModelDuck : public Duck {
    public:
        ModelDuck();
        ~ModelDuck() override;
        void display() override;
};

#endif
