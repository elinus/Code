#ifndef __EMAIL_LOGGER_H__
#define __EMAIL_LOGGER_H__

#include "Logger.h"
#include <iostream>

class EmailLogger : public Logger {
public:
  EmailLogger(int mask);
  ~EmailLogger() override;

  // Inherited via Logger
  void writeMessage(std::string msg) override;
};

#endif // !__EMAIL_LOGGER_H__
