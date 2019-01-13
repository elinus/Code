#ifndef __GARAGEDOOR_H__
#define __GARAGEDOOR_H__

#include <iostream>
#include <string>

class GarageDoor {
    public:
        GarageDoor(std::string location);
        void up();
        void down();
        void stop();
        void lightOn();
        void lightOff();
    private:
        std::string location;
};
#endif /* __GARAGEDOOR_H__ */
