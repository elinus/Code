#ifndef __CEILINGFAN_H__
#define __CEILINGFAN_H__

#include <iostream>
#include <string>

class CeilingFan {
    public:
        enum Level {
            LOW = 0,
            MEDIUM = 1,
            HIGH = 2,
        };
        CeilingFan(std::string location);
        void high();
        void medium();
        void low();
        void off();
        int getSpeed();
    private:
        std::string location;
        int level;
};

#endif /* __CEILINGFAN_H__ */
