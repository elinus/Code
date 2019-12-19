#ifndef __ADDPAYMENTTOPIC_H__
#define __ADDPAYMENTTOPIC_H__

#include "Topic.h"
#include "Observer.h"

#include <vector>

class AddPaymentTopic : public Topic {
    private:
        std::vector<Observer*> mAddPaymentObservers;
    public:
        void registerObserver(Observer* o);
        void notifyObservers(const std::string& line);
};

#endif /* __ADDPAYMENTTOPIC_H__ */
