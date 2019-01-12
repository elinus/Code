#include <Facade/Projector.h>

Projector::Projector(std::string description, DvdPlayer *dvdPlayer)
{
    this->description = description;
    this->dvdPlayer = dvdPlayer;
}

void Projector::on()
{
    std::cout << description << " on" << std::endl;
}

void Projector::off()
{
    std::cout << description << " off" << std::endl;
}

void Projector::wideScreenMode()
{
    std::cout << description << " in widescreen mode(16x9 aspect ratio)\n";
}

void Projector::tvMode()
{
    std::cout << description << " in tv mode(4x3 aspect ratio)\n";
}

std::string Projector::toString()
{
    return description;
}
