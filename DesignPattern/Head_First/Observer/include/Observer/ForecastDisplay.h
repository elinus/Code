#ifndef __FORECAST_DISPLAY_H__
#define __FORECAST_DISPLAY_H__

#include <Observer/DisplayElement.h>
#include <Observer/Observer.h>
#include <Observer/Subject.h>

#include <iostream>

class ForecastDisplay : public Observer, public DisplayElement {
public:
  ForecastDisplay(Subject *weatherData);
  void update(float temperature, float humidity, float pressure) override;
  void display() override;

private:
  float currentPressure = 29.92f;
  float lastPressure;
  Subject *weatherData;
};

#endif
