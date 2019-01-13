#include <Command/LightOnCommand.h>

LightOnCommand::LightOnCommand(Light *light)
{
    this->light = light;
}

void LightOnCommand::execute()
{
    light->on();
}
