#include <Facade/TheaterLights.h>

TheaterLights::TheaterLights(std::string description)
{
    this->description = description;
}

void TheaterLights::on()
{
    std::cout << description << " on\n";
}

void TheaterLights::off()
{
    std::cout << description << " off\n";
}

void TheaterLights::dim(int level)
{
    std::cout << description << " dimming to " << level << "%\n";
}

std::string TheaterLights::toString()
{
    return description;
}
