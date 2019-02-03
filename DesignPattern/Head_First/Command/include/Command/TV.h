#ifndef __TV_H__
#define __TV_H__

#include <iostream>
#include <string>

class TV {
public:
  TV(std::string location);
  void on();
  void off();
  void setInputChannel();

private:
  std::string location;
  int channel;
};

#endif /* __TV_H__ */
