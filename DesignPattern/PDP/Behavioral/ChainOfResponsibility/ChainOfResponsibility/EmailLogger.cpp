#include "EmailLogger.h"

EmailLogger::EmailLogger(int mask)
{
	this->mask = mask;
}

EmailLogger::~EmailLogger()
{}

void EmailLogger::writeMessage(std::string msg)
{
	std::cout << "Sending via email: " << msg << std::endl;
}
