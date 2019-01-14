#ifndef __LIGHTONCOMMAND_H__
#define __LIGHTONCOMMAND_H__

#include <Command/Command.h>
#include <Command/Light.h>
#include <string>

class LightOnCommand : public Command {
    public:
        LightOnCommand(Light *light);
        void execute();
        std::string toString();
    private:
        Light *light;
};

#endif /* __LIGHTONCOMMAND_H__ */
