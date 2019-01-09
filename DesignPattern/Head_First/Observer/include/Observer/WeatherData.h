#ifndef __WEATHER_DATA_H__
#define __WEATHER_DATA_H__

#include <Observer/Subject.h>
#include <vector>
#include <algorithm>

class WeatherData : public Subject {
    public:
        WeatherData();
        void registerObserver(Observer *o);
        void removeObserver(Observer *o);
        void notifyObservers();
        void measurementsChanged();
        void setMeasurements(float temperature, float humidity, float pressure);
    private:
        std::vector<Observer*> *observers;
        float temperature;
        float humidity;
        float pressure;
};

#endif
