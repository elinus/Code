#include <Command/SimpleRemoteControl.h>

SimpleRemoteControl::SimpleRemoteControl()
{}

void SimpleRemoteControl::setCommand(Command *command)
{
    slot = command;
}

void SimpleRemoteControl::buttonWasPressed()
{
    slot->execute();
}

