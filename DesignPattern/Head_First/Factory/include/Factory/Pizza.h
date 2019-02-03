#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <iostream>
#include <string>
#include <vector>

class Pizza {
public:
  virtual std::string getName();
  virtual void prepare();
  virtual void bake();
  virtual void cut();
  virtual void box();
  std::string toString();

protected:
  std::string name;
  std::string dough;
  std::string sauce;
  std::vector<std::string> toppings;
};

#endif // !__PIZZA_H__
