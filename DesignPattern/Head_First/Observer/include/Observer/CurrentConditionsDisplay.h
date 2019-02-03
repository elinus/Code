#ifndef __CURRENT_CONDITIONS_DISPLAY_H__
#define __CURRENT_CONDITIONS_DISPLAY_H__

#include <Observer/DisplayElement.h>
#include <Observer/Observer.h>
#include <Observer/Subject.h>

#include <iomanip>
#include <iostream>

class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
  CurrentConditionsDisplay(Subject *weatherData);
  void update(float temperature, float humidity, float pressure) override;
  void display() override;

private:
  float temperature;
  float humidity;
  Subject *weatherData;
};

#endif
