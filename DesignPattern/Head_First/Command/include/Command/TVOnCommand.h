#ifndef __TVONCOMMAND_H__
#define __TVONCOMMAND_H__

#include <Command/Command.h>
#include <Command/TV.h>

class TVOnCommand : public Command {
    public:
        TVOnCommand(TV *tv);
        void execute();
    private:
        TV *tv;
};

#endif /* __TVONCOMMAND_H__ */
