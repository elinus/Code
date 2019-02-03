#ifndef __WEATHER_DATA_H__
#define __WEATHER_DATA_H__

#include <Observer/Subject.h>
#include <algorithm>
#include <vector>

class WeatherData : public Subject {
public:
  WeatherData();
  void registerObserver(Observer *o) override;
  void removeObserver(Observer *o) override;
  void notifyObservers() override;
  void measurementsChanged();
  void setMeasurements(float temperature, float humidity, float pressure);

private:
  std::vector<Observer *> *observers;
  float temperature;
  float humidity;
  float pressure;
};

#endif
