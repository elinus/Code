#ifndef __STEREO_H__
#define __STEREO_H__

#include <iostream>
#include <string>

class Stereo {
    public:
        Stereo(std::string location);
        void on();
        void off();
        void setCD();
        void setDVD();
        void setRadio();
        void setVolume(int volume);
    private:
        std::string location;
};

#endif /* __STEREO_H__ */
