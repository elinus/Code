#ifndef __MUTEQUACK_H__
#define __MUTEQUACK_H__

#include <QuackBehaviour.h>
#include <iostream>

class MuteQuack : public QuackBehaviour {
public:
  MuteQuack();
  ~MuteQuack() override;
  void quack() override;
};

#endif
