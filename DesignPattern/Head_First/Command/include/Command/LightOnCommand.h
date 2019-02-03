#ifndef __LIGHTONCOMMAND_H__
#define __LIGHTONCOMMAND_H__

#include <Command/Command.h>
#include <Command/Light.h>
#include <string>

class LightOnCommand : public Command {
    public:
        LightOnCommand(Light *light);
        void execute() override;
        std::string toString() override;
    private:
        Light *light;
};

#endif /* __LIGHTONCOMMAND_H__ */
