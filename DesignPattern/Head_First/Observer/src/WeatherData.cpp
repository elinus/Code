#include <Observer/WeatherData.h>

WeatherData::WeatherData() { observers = new std::vector<Observer *>; }

void WeatherData::registerObserver(Observer *o) { observers->push_back(o); }

void WeatherData::removeObserver(Observer *o) {
  std::vector<Observer *>::iterator it;
  it = std::find(observers->begin(), observers->end(), o);
  if (it != observers->end()) {
    observers->erase(it);
  }
}

void WeatherData::notifyObservers() {
  for (auto &observer : *observers) {
    observer->update(temperature, humidity, pressure);
  }
}

void WeatherData::measurementsChanged() { notifyObservers(); }

void WeatherData::setMeasurements(float temperature, float humidity,
                                  float pressure) {
  this->temperature = temperature;
  this->humidity = humidity;
  this->pressure = pressure;
  measurementsChanged();
}
