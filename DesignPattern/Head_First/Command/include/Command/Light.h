#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <iostream>

class Light {
public:
  Light(std::string location);
  void on();
  void off();

private:
  std::string location;
};

#endif /* __LIGHT_H__ */
