#include <Command/CeilingFanOffCommand.h>

CeilingFanOffCommand::CeilingFanOffCommand(CeilingFan *ceilingFan)
{
    this->ceilingFan = ceilingFan;
}

void CeilingFanOffCommand::execute()
{
    ceilingFan->off();
}

std::string CeilingFanOffCommand::toString()
{
    return "CeilingFanOffCommand";
}
