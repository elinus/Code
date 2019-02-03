#include <Command/LivingroomLightOnCommand.h>

LivingroomLightOnCommand::LivingroomLightOnCommand(Light *light) {
  this->light = light;
}

void LivingroomLightOnCommand::execute() { light->on(); }

std::string LivingroomLightOnCommand::toString() {
  return "LivingroomLightOnCommand";
}
