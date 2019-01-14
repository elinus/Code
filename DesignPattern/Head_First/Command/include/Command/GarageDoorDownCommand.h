#ifndef __GARAGEDOORDOWNCOMMAND_H__
#define __GARAGEDOORDOWNCOMMAND_H__

#include <Command/Command.h>
#include <Command/GarageDoor.h>
#include <string>

class GarageDoorDownCommand : public Command {
    public:
        GarageDoorDownCommand(GarageDoor *garageDoor);
        void execute();
        std::string toString();
    private:
        GarageDoor *garageDoor;
};

#endif /* __GARAGEDOORDOWNCOMMAND_H__ */
