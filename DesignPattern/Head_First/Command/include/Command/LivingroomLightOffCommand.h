#ifndef __LIVINGROOMLIGHTOFFCOMMAND_H__
#define __LIVINGROOMLIGHTOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/Light.h>
#include <string>

class LivingroomLightOffCommand : public Command {
    public:
        LivingroomLightOffCommand(Light *light);
        void execute();
        std::string toString();
    private:
        Light *light;
};

#endif /* __LIVINGROOMLIGHTOFFCOMMAND_H__ */
