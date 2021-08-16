#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Observer.h"
#include <string>

class Topic {
    public:
        virtual ~Topic() = default;
        virtual void registerObserver(Observer* obj) = 0;
        virtual void notifyObservers(const std::string& line) = 0;
};

#endif /* __TOPIC_H__ */
