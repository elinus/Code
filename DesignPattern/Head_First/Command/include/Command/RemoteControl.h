#ifndef __REMOTECONTROL_H__
#define __REMOTECONTROL_H__

#include <Command/Command.h>
#include <Command/NoCommand.h>
#include <string>

class RemoteControl {
public:
  RemoteControl();
  void setCommand(int slot, Command *onCommand, Command *offCommand);
  void onButtonWasPushed(int slot);
  void offButtonWasPushed(int slot);
  std::string toString();

private:
  Command **onCommands;
  Command **offCommands;
};

#endif /* __REMOTECONTROL_H__ */
