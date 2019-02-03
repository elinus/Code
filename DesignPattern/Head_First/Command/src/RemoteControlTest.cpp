#include <Command/CeilingFan.h>
#include <Command/CeilingFanOffCommand.h>
#include <Command/CeilingFanOnCommand.h>
#include <Command/GarageDoor.h>
#include <Command/GarageDoorDownCommand.h>
#include <Command/GarageDoorUpCommand.h>
#include <Command/Light.h>
#include <Command/LightOffCommand.h>
#include <Command/LightOnCommand.h>
#include <Command/LivingroomLightOffCommand.h>
#include <Command/LivingroomLightOnCommand.h>
#include <Command/SimpleRemoteControl.h>

int main(int argc, char *argv[]) {
  SimpleRemoteControl *remote = new SimpleRemoteControl();
  Light *light = new Light("Kitchen");
  GarageDoor *garageDoor = new GarageDoor("");
  CeilingFan *ceilingFan = new CeilingFan("Living room");

  LightOnCommand *lightOn = new LightOnCommand(light);
  LightOffCommand *lightOff = new LightOffCommand(light);
  GarageDoorUpCommand *garageDoorUp = new GarageDoorUpCommand(garageDoor);
  GarageDoorDownCommand *garageDoorDown = new GarageDoorDownCommand(garageDoor);
  CeilingFanOnCommand *ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
  CeilingFanOffCommand *ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

  remote->setCommand(lightOn);
  remote->buttonWasPressed();
  remote->setCommand(lightOff);
  remote->buttonWasPressed();

  remote->setCommand(garageDoorUp);
  remote->buttonWasPressed();
  remote->setCommand(garageDoorDown);
  remote->buttonWasPressed();

  remote->setCommand(ceilingFanOn);
  remote->buttonWasPressed();
  remote->setCommand(ceilingFanOff);
  remote->buttonWasPressed();

  return 0;
}
