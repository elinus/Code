#ifndef __CEILINGFANOFFCOMMAND_H__
#define __CEILINGFANOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/CeilingFan.h>
#include <string>

class CeilingFanOffCommand : public Command {
    public:
        CeilingFanOffCommand(CeilingFan *ceilingFan);
        void execute();
        std::string toString();
    private:
        CeilingFan *ceilingFan;
};

#endif /* __CEILINGFANOFFCOMMAND_H__ */
