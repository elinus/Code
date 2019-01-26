#include <Observer/WeatherData.h>
#include <Observer/CurrentConditionsDisplay.h>
#include <Observer/StatisticsDisplay.h>
#include <Observer/ForecastDisplay.h>
#include <Observer/HeatIndexDisplay.h>

int main(int argc, char *argv[])
{
    WeatherData *weatherData =  new WeatherData();
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay *statsDisplay = new StatisticsDisplay(weatherData);
    ForecastDisplay *forcastDisplay = new ForecastDisplay(weatherData);
    HeatIndexDisplay *heatIndex = new HeatIndexDisplay(weatherData);

    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.2f);
    weatherData->setMeasurements(78, 90, 29.2f);
    
    delete currentDisplay;
    delete statsDisplay;
    delete forcastDisplay;
    delete heatIndex;

    return 0;
}
