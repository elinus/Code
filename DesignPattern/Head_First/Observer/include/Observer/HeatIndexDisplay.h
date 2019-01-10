#ifndef __HEAT_INDEX_DISPLAY_H__
#define __HEAT_INDEX_DISPLAY_H__

#include <Observer/Observer.h>
#include <Observer/DisplayElement.h>
#include <Observer/Subject.h>

#include <iostream>

class HeatIndexDisplay : public Observer, public DisplayElement {
    public:
        HeatIndexDisplay(Subject *weatherData);
        void update(float temperature, float humidity, float pressure);
        void display();
    private:
        float computeHeatIndex(float t, float rh);
        float heatIndex = 0.0f;
        Subject *weatherData;
};

#endif
