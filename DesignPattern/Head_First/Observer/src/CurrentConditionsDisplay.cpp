#include <Observer/CurrentConditionsDisplay.h>

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *weatherData) {
  this->weatherData = weatherData;
  weatherData->registerObserver(this);
}

void CurrentConditionsDisplay::update(float temperature, float humidity,
                                      float pressure) {
  this->temperature = temperature;
  this->humidity = humidity;
  display();
}

void CurrentConditionsDisplay::display() {
  std::cout << std::setprecision(2) << "Current conditions: " << temperature
            << "F degree and " << humidity << "\% humidity\n";
}
