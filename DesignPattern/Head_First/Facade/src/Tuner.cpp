#include <Facade/Tuner.h>

Tuner::Tuner(std::string description, Amplifier *amplifier)
{
    this->description = description;
    this->amplifier = amplifier;
}

void Tuner::on()
{
    std::cout << description << " on\n";
}

void Tuner::off()
{
    std::cout << description << " off\n";
}

void Tuner::setFrequency(double frequency)
{ 
    std::cout << description << " setting frequency to " << frequency << "\n";
    this->frequency = frequency;
}

void Tuner::setAm()
{
    std::cout << description << " setting AM mode\n";
}

void Tuner::setFm()
{
    std::cout << description << " setting FM mode\n";
}

std::string Tuner::toString()
{
    return description;
}
