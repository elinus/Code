#include "StdoutLogger.h"

StdoutLogger::StdoutLogger(int mask)
{
	this->mask = mask;
}

StdoutLogger::~StdoutLogger()
{}

void StdoutLogger::writeMessage(std::string msg)
{
	std::cout << "Writing to stdout: " << msg << std::endl;
}
