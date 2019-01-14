#include <Command/GarageDoorDownCommand.h>

GarageDoorDownCommand::GarageDoorDownCommand(GarageDoor *garageDoor){
    this->garageDoor = garageDoor;
}

void GarageDoorDownCommand::execute()
{
    garageDoor->down();
}

std::string GarageDoorDownCommand::toString()
{
    return "GarageDoorDownCommand";
}
