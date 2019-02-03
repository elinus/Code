#ifndef __CEILINGFANOFFCOMMAND_H__
#define __CEILINGFANOFFCOMMAND_H__

#include <Command/CeilingFan.h>
#include <Command/Command.h>
#include <string>

class CeilingFanOffCommand : public Command {
public:
  CeilingFanOffCommand(CeilingFan *ceilingFan);
  void execute() override;
  std::string toString() override;

private:
  CeilingFan *ceilingFan;
};

#endif /* __CEILINGFANOFFCOMMAND_H__ */
