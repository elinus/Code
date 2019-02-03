#ifndef __WHIP_H__
#define __WHIP_H__

#include <Decorator/CondimentDecorator.h>

class Whip : public CondimentDecorator {
public:
  Whip(Beverage *beverage);
  std::string getDescription() override;
  double cost() override;

private:
  Beverage *beverage;
};

#endif
