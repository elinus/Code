#ifndef __SQUEAK_H__
#define __SQUEAK_H__

#include <QuackBehaviour.h>
#include <iostream>

class Squeak : public QuackBehaviour {
public:
  Squeak();
  ~Squeak() override;
  void quack() override;
};

#endif
