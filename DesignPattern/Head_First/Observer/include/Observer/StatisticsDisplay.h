#ifndef __STATISTICS_DISPLAY_H__
#define __STATISTICS_DISPLAY_H__

#include <Observer/DisplayElement.h>
#include <Observer/Observer.h>
#include <Observer/Subject.h>

#include <iomanip>
#include <iostream>

class StatisticsDisplay : public Observer, public DisplayElement {
public:
  StatisticsDisplay(Subject *weatherData);
  void update(float temperature, float humidity, float pressure) override;
  void display() override;

private:
  float maxTemp = 0.0f;
  float minTemp = 200.0f;
  float tempSum = 0.0f;
  int numReadings;
  Subject *weatherData;
};

#endif
