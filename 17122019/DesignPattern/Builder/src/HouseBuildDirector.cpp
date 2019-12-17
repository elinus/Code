#include "HouseBuildDirector.h"

HouseBuildDirector::HouseBuildDirector(HouseBuilder *houseBuilder) {
  this->houseBuilder = houseBuilder;
}

House *HouseBuildDirector::construct() {
  return houseBuilder->buildFloor()->buildWall()->buildRoof()->build();
}
