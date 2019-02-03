#ifndef __STEREOONWITHCDCOMMAND_H__
#define __STEREOONWITHCDCOMMAND_H__

#include <Command/Command.h>
#include <Command/Stereo.h>
#include <string>

class StereoOnWithCDCommand : public Command {
    public:
        StereoOnWithCDCommand(Stereo *stereo);
        void execute() override;
        std::string toString() override;
    private:
        Stereo *stereo;
};

#endif /* __STEREOONWITHCDCOMMAND_H__ */
