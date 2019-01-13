#ifndef __GARAGEDOORUPCOMMAND_H__
#define __GARAGEDOORUPCOMMAND_H__

#include <Command/Command.h>
#include <Command/GarageDoor.h>

class GarageDoorUpCommand : public Command {
    public:
        GarageDoorUpCommand(GarageDoor *garageDoor);
        void execute();
    private:
        GarageDoor *garageDoor;
};

#endif /* __GARAGEDOORUPCOMMAND_H__ */
