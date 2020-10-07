#ifndef __COMPLETEORDERTOPIC_H__
#define __COMPLETEORDERTOPIC_H__

#include "Topic.h"
#include "Observer.h"

#include <vector>

class CompleteOrderTopic : public Topic {
    private:
        std::vector<Observer*> mCompleteOrderObservers;
    public:
        void registerObserver(Observer* o);
        void notifyObservers(const std::string& line);
};

#endif /* __COMPLETEORDERTOPIC_H__ */
