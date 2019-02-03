#ifndef __LIVINGROOMLIGHTONCOMMAND_H__
#define __LIVINGROOMLIGHTONCOMMAND_H__

#include <Command/Command.h>
#include <Command/Light.h>
#include <string>

class LivingroomLightOnCommand : public Command {
    public:
        LivingroomLightOnCommand(Light *light);
        void execute() override;
        std::string toString() override;
    private:
        Light *light;
};

#endif /* __LIVINGROOMLIGHTONCOMMAND_H__ */
