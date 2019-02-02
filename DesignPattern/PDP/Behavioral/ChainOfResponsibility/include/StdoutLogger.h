#ifndef __STD_OUT_LOGGER_H__
#define __STD_OUT_LOGGER_H__

#include "Logger.h"
#include <iostream>

class  StdoutLogger : public Logger {
public:
	StdoutLogger(int mask);
	~StdoutLogger() override;

	// Inherited via Logger
	void writeMessage(std::string msg) override;
};

#endif // !__STD_OUT_LOGGER_H__
