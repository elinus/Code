#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <string>

class Screen {
    public:
        Screen(std::string description);
        void up();
        void down();    
        std::string toString();
    private:
        std::string description;
};

#endif /* __SCREEN_H__ */
