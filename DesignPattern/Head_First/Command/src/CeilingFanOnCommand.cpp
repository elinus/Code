#include <Command/CeilingFanOnCommand.h>

CeilingFanOnCommand::CeilingFanOnCommand(CeilingFan *ceilingFan) {
  this->ceilingFan = ceilingFan;
}

void CeilingFanOnCommand::execute() { ceilingFan->high(); }

std::string CeilingFanOnCommand::toString() { return "CeilingFanOnCommand"; }
