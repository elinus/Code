#ifndef __NOCOMMAND_H__
#define __NOCOMMAND_H__

#include <Command/Command.h>
#include <string>

class NoCommand : public Command {
    public:
        void execute();
        std::string toString();
};

#endif /* __NOCOMMAND_H__ */
