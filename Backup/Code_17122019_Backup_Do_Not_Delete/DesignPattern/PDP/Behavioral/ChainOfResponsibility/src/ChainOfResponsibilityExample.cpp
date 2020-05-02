#include "EmailLogger.h"
#include "Logger.h"
#include "StderrLogger.h"
#include "StdoutLogger.h"

int main() {

  Logger *logger, *logger1, *logger2;
  logger = new StdoutLogger(Logger::DEBUG);
  logger1 = logger->setNext(new EmailLogger(Logger::NOTICE));
  logger2 = logger1->setNext(new StderrLogger(Logger::ERR));

  logger->message("Entering function y.", Logger::DEBUG);
  logger->message("Step1 completed.", Logger::NOTICE);
  logger->message("An error has occured.", Logger::ERR);
  return 0;
}
