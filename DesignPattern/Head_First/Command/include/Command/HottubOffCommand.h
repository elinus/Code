#ifndef __HOTTUBOFFCOMMAND_H__
#define __HOTTUBOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/Hottub.h>
#include <string>

class HottubOffCommand : public Command {
    public:
        HottubOffCommand(Hottub *hottub);
        void execute();
        std::string toString();
    private:
        Hottub *hottub;
};

#endif /* __HOTTUBOFFCOMMAND_H__ */
