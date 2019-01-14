#include <Command/RemoteControl.h>

RemoteControl::RemoteControl()
{
    onCommands = new Command*[7];
    offCommands = new Command*[7];

    Command *noCommand = new NoCommand();
    for (int i = 0; i < 7; i++) {
        onCommands[i] = noCommand;
        offCommands[i] = noCommand;
    }
}

void RemoteControl::setCommand(int slot, Command *onCommand, Command *offCommand)
{
    onCommands[slot] = onCommand;
    offCommands[slot] = offCommand;
}

void RemoteControl::onButtonWasPushed(int slot)
{
    onCommands[slot]->execute();
}

void RemoteControl::offButtonWasPushed(int slot)
{
    offCommands[slot]->execute();
}

std::string RemoteControl::toString()
{
    std::string stringBuff;
    stringBuff.append("\n----- Remote Control -----\n");
    for (int i = 0; i < 7; i++) {
        stringBuff.append("[slot " + std::to_string(i) + "] ");
        stringBuff.append(onCommands[i]->toString());
        stringBuff.append("    ");
        stringBuff.append(offCommands[i]->toString());
        stringBuff.append("\n");
    }
    return stringBuff;
}
