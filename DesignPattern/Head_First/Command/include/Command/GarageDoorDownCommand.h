#ifndef __GARAGEDOORDOWNCOMMAND_H__
#define __GARAGEDOORDOWNCOMMAND_H__

#include <Command/Command.h>
#include <Command/GarageDoor.h>

class GarageDoorDownCommand : public Command {
    public:
        GarageDoorDownCommand(GarageDoor *garageDoor);
        void execute();
    private:
        GarageDoor *garageDoor;
};

#endif /* __GARAGEDOORDOWNCOMMAND_H__ */
