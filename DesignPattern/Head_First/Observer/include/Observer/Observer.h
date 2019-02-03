#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Observer {
public:
  virtual void update(float temp, float humidity, float pressure) = 0;
};

#endif
