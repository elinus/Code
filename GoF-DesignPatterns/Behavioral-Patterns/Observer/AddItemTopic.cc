#include "AddItemTopic.h"

void AddItemTopic::registerObserver(Observer *o) {
  mAddItemObservers.push_back(o);
}

void AddItemTopic::notifyObservers(const std::string &line) {
  for (auto it = mAddItemObservers.begin(); it != mAddItemObservers.end();
       ++it) {
    (*it)->update(line);
  }
}
