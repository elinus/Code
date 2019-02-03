#include <Command/RemoteControl.h>
#include <Command/Light.h>
#include <Command/LightOnCommand.h>
#include <Command/LightOffCommand.h>
#include <Command/LivingroomLightOnCommand.h>
#include <Command/LivingroomLightOffCommand.h>
#include <Command/GarageDoor.h>
#include <Command/GarageDoorUpCommand.h>
#include <Command/GarageDoorDownCommand.h>
#include <Command/CeilingFan.h>
#include <Command/CeilingFanOnCommand.h>
#include <Command/CeilingFanOffCommand.h>
#include <iostream>

int main (int argc, char *argv[])
{
    auto *remoteControl = new RemoteControl();
    Light *light = new Light("Kitchen");
    Light *livingRoomLight = new Light("Livingroom");
    GarageDoor *garageDoor = new GarageDoor("");
    CeilingFan *ceilingFan = new CeilingFan("Living room");


    auto *lightOn = new LightOnCommand(light);
    auto *lightOff = new LightOffCommand(light);
    auto *livingRoomLightOn 
        = new LivingroomLightOnCommand(livingRoomLight);
    auto *livingRoomLightOff 
        = new LivingroomLightOffCommand(livingRoomLight);
    auto *garageDoorUp = new GarageDoorUpCommand(garageDoor);
    auto *garageDoorDown = new GarageDoorDownCommand(garageDoor);
    auto *ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
    auto *ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

    remoteControl->setCommand(0, lightOn, lightOff);
    remoteControl->setCommand(1, livingRoomLightOn, livingRoomLightOff);
    remoteControl->setCommand(2, ceilingFanOn, ceilingFanOff);
    remoteControl->setCommand(3, garageDoorUp, garageDoorDown);


    std::cout << remoteControl->toString() << std::endl;

    remoteControl->onButtonWasPushed(0);
    remoteControl->offButtonWasPushed(0);
    remoteControl->onButtonWasPushed(1);
    remoteControl->offButtonWasPushed(1);
    remoteControl->onButtonWasPushed(2);
    remoteControl->offButtonWasPushed(2);
    remoteControl->onButtonWasPushed(3);
    remoteControl->offButtonWasPushed(3);
    return 0;
}

