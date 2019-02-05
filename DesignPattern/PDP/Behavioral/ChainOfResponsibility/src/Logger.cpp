#include "Logger.h"

Logger::Logger() {}

Logger::~Logger() {
  if (next != nullptr) {
    delete next;
  }
}

Logger *Logger::setNext(Logger *log) {
  next = log;
  return log;
}

void Logger::message(std::string msg, int priority) {
  if (priority <= mask) {
    writeMessage(msg);
  }

  if (next != nullptr) {
    next->message(msg, priority);
  }
}
