#ifndef __CEILINGFANONCOMMAND_H__
#define __CEILINGFANONCOMMAND_H__

#include <Command/Command.h>
#include <Command/CeilingFan.h>
#include <string>

class CeilingFanOnCommand : public Command {
    public:
        CeilingFanOnCommand(CeilingFan *ceilingFan);
        void execute();
        std::string toString();
    private:
        CeilingFan *ceilingFan;
};

#endif /* __CEILINGFANONCOMMAND_H__ */
