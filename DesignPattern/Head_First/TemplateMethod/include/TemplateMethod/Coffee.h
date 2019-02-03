#ifndef __COFFEE_H__
#define __COFFEE_H__

#include <TemplateMethod/CaffeineBeverage.h>
#include <string>

class Coffee : public CaffeineBeverage {
public:
  void brew() override;
  void addCondiments() override;
  bool customerWantsCondiments() override;

private:
  std::string getUserInput();
};

#endif
