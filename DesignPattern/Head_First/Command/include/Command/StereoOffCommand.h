#ifndef __STEREOOFFCOMMAND_H__
#define __STEREOOFFCOMMAND_H__

#include <Command/Command.h>
#include <Command/Stereo.h>
#include <string>

class StereoOffCommand : public Command {
    public:
        StereoOffCommand(Stereo *stereo);
        void execute() override;
        std::string toString() override;
    private:
        Stereo *stereo;
};

#endif /* __STEREOOFFCOMMAND_H__ */
