#ifndef __MODEL_DUCK__
#define __MODEL_DUCK__

#include <iostream>
#include <Strategy/Duck.h>
#include <Strategy/FlyNoWay.h>
#include <Strategy/Quack.h>

class ModelDuck : public Duck {
    public:
        ModelDuck();
        void display();
};

#endif
