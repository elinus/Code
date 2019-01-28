#ifndef __EMAIL_LOGGER_H__
#define __EMAIL_LOGGER_H__

#include "Logger.h"
#include <iostream>

class  EmailLogger : public Logger {
public:
	EmailLogger(int mask);
	~EmailLogger();

	// Inherited via Logger
	virtual void writeMessage(std::string msg) override;
};

#endif // !__EMAIL_LOGGER_H__
