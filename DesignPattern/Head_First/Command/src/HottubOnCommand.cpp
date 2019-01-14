#include <Command/HottubOnCommand.h>

HottubOnCommand::HottubOnCommand(Hottub *hottub) {
    this->hottub = hottub;
}

void HottubOnCommand::execute()
{
    hottub->on();
    hottub->heat();
    hottub->bubblesOn();
}

std::string HottubOnCommand::toString()
{
    return "HottubOnCommand";
}
