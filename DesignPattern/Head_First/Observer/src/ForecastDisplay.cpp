#include <Observer/ForecastDisplay.h>

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
  this->weatherData = weatherData;
  weatherData->registerObserver(this);
}

void ForecastDisplay::update(float temperature, float humidity,
                             float pressure) {
  lastPressure = currentPressure;
  currentPressure = pressure;
  display();
}

void ForecastDisplay::display() {
  std::cout << "Forecast: ";
  if (currentPressure > lastPressure) {
    std::cout << "Improving weather on the way!\n";
  } else if (currentPressure == lastPressure) {
    std::cout << "More of the same\n";
  } else if (currentPressure < lastPressure) {
    std::cout << "Watchout for cooler, rainy weather\n";
  }
}
