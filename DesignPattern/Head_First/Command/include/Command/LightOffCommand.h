#ifndef __LIGHTOFFCOMMAND_H__
#define __LIGHTOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/Light.h>
#include <string>

class LightOffCommand : public Command {
    public:
        LightOffCommand(Light *light);
        void execute();
        std::string toString();
    private:
        Light *light;
};

#endif /* __LIGHTOFFCOMMAND_H__ */
