#include "ConcreteHouseBuilder.h"
#include "WoodenHouseBuilder.h"
#include "HouseBuilder.h"
#include "HouseBuildDirector.h"
#include <iostream>

int main() {
    HouseBuilder *builder = new ConcreteHouseBuilder();
    HouseBuildDirector *houseBuildDirector = new HouseBuildDirector(builder);
    std::cout << houseBuildDirector->construct()->toString();
    return 0;
}
