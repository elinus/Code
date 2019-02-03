#include <Observer/StatisticsDisplay.h>

StatisticsDisplay::StatisticsDisplay(Subject *weatherData) {
  this->weatherData = weatherData;
  weatherData->registerObserver(this);
}

void StatisticsDisplay::update(float temperature, float humidity,
                               float pressure) {
  tempSum += temperature;
  numReadings++;
  if (temperature > maxTemp) {
    maxTemp = temperature;
  }
  if (temperature < minTemp) {
    minTemp = temperature;
  }

  display();
}

void StatisticsDisplay::display() {
  std::cout << std::setprecision(5)
            << "Avg/MAx/Min temperature = " << (tempSum / numReadings) << "/"
            << maxTemp << "/" << minTemp << "\n";
}
