#ifndef __HOTTUBONCOMMAND_H__
#define __HOTTUBONCOMMAND_H__

#include <Command/Command.h>
#include <Command/Hottub.h>
#include <string>

class HottubOnCommand : public Command {
    public:
        HottubOnCommand(Hottub *hottub);
        void execute() override;
        std::string toString() override;
    private:
        Hottub *hottub;
};

#endif /* __HOTTUBONCOMMAND_H__ */
