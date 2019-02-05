#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

class Logger {
public:
  enum ErrorType {
    ERR = 3,
    NOTICE = 5,
    DEBUG = 7,
  };
  Logger();
  virtual ~Logger();
  Logger *setNext(Logger *log);
  void message(std::string msg, int priority);

protected:
  int mask;
  Logger *next;
  virtual void writeMessage(std::string msg) = 0;
};

#endif // !__LOGGER_H__
