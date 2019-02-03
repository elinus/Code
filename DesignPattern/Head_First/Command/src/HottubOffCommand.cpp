#include <Command/HottubOffCommand.h>

HottubOffCommand::HottubOffCommand(Hottub *hottub) { this->hottub = hottub; }

void HottubOffCommand::execute() {
  hottub->cool();
  hottub->off();
}

std::string HottubOffCommand::toString() { return "HottubOffCommand"; }
