#ifndef __TEA_H__
#define __TEA_H__

#include <TemplateMethod/CaffeineBeverage.h>
#include <string>

class Tea : public CaffeineBeverage {
public:
  void brew() override;
  void addCondiments() override;
  bool customerWantsCondiments() override;

private:
  std::string getUserInput();
};

#endif
