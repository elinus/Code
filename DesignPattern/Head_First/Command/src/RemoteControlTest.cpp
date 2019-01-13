#include <Command/SimpleRemoteControl.h>
#include <Command/Light.h>
#include <Command/LightOnCommand.h>
#include <Command/LightOffCommand.h>
#include <Command/GarageDoor.h>
#include <Command/GarageDoorUpCommand.h>
#include <Command/GarageDoorDownCommand.h>

int main (int argc, char *argv[])
{
    SimpleRemoteControl *remote = new SimpleRemoteControl();
    Light *light = new Light("Bedroom");
    GarageDoor *garageDoor = new GarageDoor("");

    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);
    GarageDoorUpCommand *garageDoorUp = new GarageDoorUpCommand(garageDoor);
    GarageDoorDownCommand *garageDoorDown = new GarageDoorDownCommand(garageDoor);

    remote->setCommand(lightOn);
    remote->buttonWasPressed();
    remote->setCommand(lightOff);
    remote->buttonWasPressed();
    
    remote->setCommand(garageDoorUp);
    remote->buttonWasPressed();
    remote->setCommand(garageDoorDown);
    remote->buttonWasPressed();

    return 0;
}

