#include "StderrLogger.h"

StderrLogger::StderrLogger(int mask)
{
	this->mask = mask;
}

StderrLogger::~StderrLogger()
{}

void StderrLogger::writeMessage(std::string msg)
{
	std::cout << "'Sending to stderr: " << msg << std::endl;
}
