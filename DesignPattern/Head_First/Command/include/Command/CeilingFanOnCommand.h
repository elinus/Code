#ifndef __CEILINGFANONCOMMAND_H__
#define __CEILINGFANONCOMMAND_H__

#include <Command/CeilingFan.h>
#include <Command/Command.h>
#include <string>

class CeilingFanOnCommand : public Command {
public:
  CeilingFanOnCommand(CeilingFan *ceilingFan);
  void execute() override;
  std::string toString() override;

private:
  CeilingFan *ceilingFan;
};

#endif /* __CEILINGFANONCOMMAND_H__ */
