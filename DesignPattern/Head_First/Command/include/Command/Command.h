#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <string>

class Command {
    public:
        virtual void execute() = 0;
        virtual std::string toString() = 0;
};

#endif /* __COMMAND_H__ */
