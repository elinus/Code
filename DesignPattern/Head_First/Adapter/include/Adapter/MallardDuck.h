#ifndef __MALLARD_DUCK_H__
#define __MALLARD_DUCK_H__

#include <Adapter/Duck.h>
#include <iostream>

class MallardDuck : public Duck {
public:
  void quack() override;
  void fly() override;
};

#endif
