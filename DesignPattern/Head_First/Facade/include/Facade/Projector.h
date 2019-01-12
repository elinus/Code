#ifndef __PROJECTOR_H__
#define __PROJECTOR_H__

#include <Facade/DvdPlayer.h>
#include <iostream>
#include <string>

class Projector {
    public:
        Projector(std::string description, DvdPlayer *dvdPlayer);
        void on();
        void off();
        void wideScreenMode();
        void tvMode();
        std::string toString();
    private:
        std::string description;
        DvdPlayer *dvdPlayer;
};

#endif /* __PROJECTOR_H__ */
