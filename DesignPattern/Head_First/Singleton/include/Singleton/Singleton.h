#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <string>

class Singleton {
    public:
        static Singleton* getInstance();
        std::string getDescription();
    private:
        static Singleton *instance;
        Singleton();
};

#endif
