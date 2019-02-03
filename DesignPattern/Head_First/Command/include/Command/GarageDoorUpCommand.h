#ifndef __GARAGEDOORUPCOMMAND_H__
#define __GARAGEDOORUPCOMMAND_H__

#include <Command/Command.h>
#include <Command/GarageDoor.h>
#include <string>

class GarageDoorUpCommand : public Command {
public:
  GarageDoorUpCommand(GarageDoor *garageDoor);
  void execute() override;
  std::string toString() override;

private:
  GarageDoor *garageDoor;
};

#endif /* __GARAGEDOORUPCOMMAND_H__ */
