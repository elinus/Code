#include <Command/GarageDoorUpCommand.h>

GarageDoorUpCommand::GarageDoorUpCommand(GarageDoor *garageDoor){
    this->garageDoor = garageDoor;
}

void GarageDoorUpCommand::execute()
{
    garageDoor->up();
}

std::string GarageDoorUpCommand::toString()
{
    return "GarageDoorUpCommand";
}
