#include <Facade/Amplifier.h>

Amplifier::Amplifier(std::string description)
{
    this->description = description;
}

void Amplifier::on()
{
    std::cout << description << " on" << std::endl;
}

void Amplifier::off()
{
    std::cout << description <<" off" << std::endl;
}

void Amplifier::setStereoSound()
{
    std::cout << description << " stereo mode on" << std::endl;
}

void Amplifier::setSurroundSound()
{
    std::cout << description 
        << " srround sound on(5 speakers, 1 subwoofer)" << std::endl;
}

void Amplifier::setVolume(int level)
{
    std::cout << description << " setting volume to " << level << std::endl;
}

void Amplifier::setTuner(Tuner *tuner)
{
    std::cout << description << " setting tuner to " << dvd << std::endl;
    this->tuner = tuner;
}

void Amplifier::setDvd(DvdPlayer *dvd)
{
    std::cout << description << " setting DVD player to " << dvd << std::endl;
    this->dvd = dvd;
}

void Amplifier::setCd(CdPlayer *cd)
{
    std::cout << description << " setting CD player to " << cd << std::endl;
}

std::string Amplifier::toString()
{
    return description;
}
