#include "AddPaymentTopic.h"

void AddPaymentTopic::registerObserver(Observer *o) {
  mAddPaymentObservers.push_back(o);
}

void AddPaymentTopic::notifyObservers(const std::string &line) {
  for (auto it = mAddPaymentObservers.begin(); it != mAddPaymentObservers.end();
       ++it) {
    (*it)->update(line);
  }
}
