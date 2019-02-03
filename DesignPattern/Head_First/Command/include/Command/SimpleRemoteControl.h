#ifndef __SIMPLEREMOTECONTROL_H__
#define __SIMPLEREMOTECONTROL_H__

#include <Command/Command.h>

class SimpleRemoteControl {
public:
  SimpleRemoteControl();
  void setCommand(Command *command);
  void buttonWasPressed();

private:
  Command *slot;
};

#endif /* __SIMPLEREMOTECONTROL_H__ */
