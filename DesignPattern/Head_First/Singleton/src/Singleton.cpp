#include <Singleton/Singleton.h>
#include <mutex>

std::mutex lock;
Singleton* Singleton::instance = nullptr;

Singleton::Singleton()
{}

Singleton* Singleton::getInstance()
{
    if(instance == nullptr) {
        lock.lock();
        if(instance == nullptr) {
            instance = new Singleton();
        }
        lock.unlock();
    }
    return instance;
}

std::string Singleton::getDescription()
{
    return std::string("I'm a thread safe Singleton!");
}
