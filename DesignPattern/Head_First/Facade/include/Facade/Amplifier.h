#ifndef __AMPLIFIER_H__
#define __AMPLIFIER_H__

#include <Facade/Tuner.h>
#include <Facade/DvdPlayer.h>
#include <Facade/CdPlayer.h>
#include <iostream>
#include <string>

class CdPlayer;
class DvdPlayer;
class Tuner;

class Amplifier {
    public:
        Amplifier(std::string description);
        void on();
        void off();
        void setStereoSound();
        void setSurroundSound();
        void setVolume(int level);
        void setTuner(Tuner *tuner);
        void setDvd(DvdPlayer *dvd);
        void setCd(CdPlayer *cd);
        std::string toString();
    private:
        std::string description;
        Tuner *tuner;
        DvdPlayer *dvd;
        CdPlayer *cd;
};

#endif /* __AMPLIFIER_H__ */
