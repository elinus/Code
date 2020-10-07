#include "HouseBuildDirector.h"

HouseBuildDirector::HouseBuildDirector(HouseBuilder *builder) {
    mBuilder = builder;
}

House* HouseBuildDirector::construct() {
    return mBuilder->buildFloor()->buildWall()->buildRoof()->build();
}
