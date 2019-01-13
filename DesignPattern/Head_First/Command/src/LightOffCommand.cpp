#include <Command/LightOffCommand.h>

LightOffCommand::LightOffCommand(Light *light)
{
    this->light = light;
}

void LightOffCommand::execute()
{
    light->off();
}
