#include <Command/Stereo.h>

Stereo::Stereo(std::string location)
{
    this->location = location;
}

void Stereo::on()
{
    std::cout << location << " stereo is on\n";
}

void Stereo::off()
{
    std::cout << location << " stereo is off\n"; 
}

void Stereo::setCD()
{
    std::cout << location << " stereo is set for CD input\n";
}

void Stereo::setDVD()
{
    std::cout << location << " stereo is set for DVD input\n";
}

void Stereo::setRadio()
{
    std::cout << location << " stereo is set for Radio\n";
}

void Stereo::setVolume(int volume)
{
    std::cout << location << " stereo volume is set to" 
        << volume << "\n";
}
