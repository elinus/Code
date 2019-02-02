#ifndef __FLY_NO_WAY__
#define __FLY_NO_WAY__

#include <FlyBehaviour.h>
#include <iostream>

class FlyNoWay : public FlyBehaviour {
public:
  FlyNoWay();
  ~FlyNoWay() override;
  void fly() override;
};

#endif
