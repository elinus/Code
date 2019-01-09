#ifndef __CURRENT_CONDITIONS_DISPLAY_H__
#define __CURRENT_CONDITIONS_DISPLAY_H__

#include <Observer/Observer.h>
#include <Observer/DisplayElement.h>
#include <Observer/Subject.h>

#include <iostream>

class CurrentConditionsDisplay : public Observer, public DisplayElement {
    public:
        CurrentConditionsDisplay(Subject *weatherData);
        void update(float temperature, float humidity, float pressure);
        void display();
    private:
        float temperature;
        float humidity;
        Subject *weatherData;
};

#endif
