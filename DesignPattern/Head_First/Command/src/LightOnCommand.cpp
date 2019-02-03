#include <Command/LightOnCommand.h>

LightOnCommand::LightOnCommand(Light *light) { this->light = light; }

void LightOnCommand::execute() { light->on(); }

std::string LightOnCommand::toString() { return "LightOnCommand"; }
