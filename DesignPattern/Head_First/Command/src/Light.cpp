#include <Command/Light.h>

Light::Light(std::string location)
{
    this->location = location;
}

void Light::on()
{
    std::cout << location << " light is on\n";
}

void Light::off()
{
    std::cout << location << " light is off\n";
}
