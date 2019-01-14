#ifndef __TVOFFCOMMAND_H__
#define __TVOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/TV.h>

class TVOffCommand : public Command {
    public:
        TVOffCommand(TV *tv);
        void execute();
    private:
        TV *tv;
};

#endif /* __TVOFFCOMMAND_H__ */
