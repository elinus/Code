#ifndef __POPCORNPOPPER_H__
#define __POPCORNPOPPER_H__

#include <iostream>
#include <string>

class PopcornPopper {
    public:
        PopcornPopper(std::string description);
        void on();
        void off();
        void pop();
        std::string toString();
    private:
        std::string description;
};

#endif /* __POPCORNPOPPER_H__ */
