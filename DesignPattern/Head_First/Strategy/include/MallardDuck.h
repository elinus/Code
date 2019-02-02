#ifndef __MALLARD_DUCK__
#define __MALLARD_DUCK__

#include <Duck.h>
#include <FlyWithWings.h>
#include <Quack.h>
#include <iostream>

class MallardDuck : public Duck {
public:
  MallardDuck();
  ~MallardDuck() override;
  void display() override;
};

#endif
