#ifndef __TUNER_H__
#define __TUNER_H__

#include <Facade/Amplifier.h>
#include <iostream>
#include <string>

class Amplifier;

class Tuner {
    public:
        Tuner(std::string description, Amplifier *amplifier);
        void on();
        void off();
        void setFrequency(double frequency);
        void setAm();
        void setFm();
        std::string toString();
    private:
        std::string description;
        Amplifier *amplifier;
        double frequency;
};

#endif /* __TUNER_H__ */
