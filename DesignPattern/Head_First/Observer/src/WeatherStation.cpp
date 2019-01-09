#include <Observer/WeatherData.h>
#include <Observer/CurrentConditionsDisplay.h>

int main(int argc, char *argv[])
{
    WeatherData *weatherData =  new WeatherData();
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    weatherData->setMeasurements(80, 65, 30.4f);
    return 0;
}
