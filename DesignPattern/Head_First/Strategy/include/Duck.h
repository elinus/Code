#ifndef __DUCK_H__
#define __DUCK_H__

#include <FlyBehaviour.h>
#include <QuackBehaviour.h>
#include <iostream>

class Duck {
public:
  Duck();
  virtual ~Duck();
  virtual void display() = 0;
  void performFly();
  void performQuack();
  void swim();
  void setFlyBehaviour(FlyBehaviour *fb);
  void setQuackBehaviour(QuackBehaviour *qb);

protected:
  FlyBehaviour *flyBehaviour;
  QuackBehaviour *quackBehaviour;
};

#endif
