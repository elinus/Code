#include <Command/StereoOffCommand.h>

StereoOffCommand::StereoOffCommand(Stereo *stereo) { this->stereo = stereo; }

void StereoOffCommand::execute() { stereo->off(); }

std::string StereoOffCommand::toString() { return "StereoOffCommand"; }
