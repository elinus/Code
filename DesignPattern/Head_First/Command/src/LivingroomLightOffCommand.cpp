#include <Command/LivingroomLightOffCommand.h>

LivingroomLightOffCommand::LivingroomLightOffCommand(Light *light) {
  this->light = light;
}

void LivingroomLightOffCommand::execute() { light->off(); }

std::string LivingroomLightOffCommand::toString() {
  return "LivingroomLightOffCommand";
}
