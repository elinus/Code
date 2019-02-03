#ifndef __THEATERLIGHTS_H__
#define __THEATERLIGHTS_H__

#include <iostream>
#include <string>

class TheaterLights {
public:
  TheaterLights(std::string description);
  void on();
  void off();
  void dim(int level);
  std::string toString();

private:
  std::string description;
};

#endif /* __THEATERLIGHTS_H__ */
