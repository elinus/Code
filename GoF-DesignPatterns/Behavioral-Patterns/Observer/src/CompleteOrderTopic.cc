#include "CompleteOrderTopic.h"

void CompleteOrderTopic::registerObserver(Observer *o) {
  mCompleteOrderObservers.push_back(o);
}

void CompleteOrderTopic::notifyObservers(const std::string &line) {
  for (auto it = mCompleteOrderObservers.begin();
       it != mCompleteOrderObservers.end(); ++it) {
    (*it)->update(line);
  }
}
