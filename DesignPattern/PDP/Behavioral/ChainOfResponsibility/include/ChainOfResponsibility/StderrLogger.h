#ifndef __STD_ERR_LOGGER_H__
#define __STD_ERR_LOGGER_H__

#include "Logger.h"
#include <iostream>

class  StderrLogger : public Logger {
public:
	StderrLogger(int mask);
	~StderrLogger();

	// Inherited via Logger
	virtual void writeMessage(std::string msg) override;
};

#endif // !__STD_ERR_LOGGER_H__
