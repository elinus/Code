#ifndef __ADDITEMTOPIC_H__
#define __ADDITEMTOPIC_H__

#include "Topic.h"
#include "Observer.h"

#include <vector>

class AddItemTopic : public Topic {
    private:
        std::vector<Observer*> mAddItemObservers;
    public:
        void registerObserver(Observer* o);
        void notifyObservers(const std::string& line);
};

#endif /* __ADDITEMTOPIC_H__ */
