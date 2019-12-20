#include "ConcreteHouseBuilder.h"

ConcreteHouseBuilder::ConcreteHouseBuilder() {
    mHouse = new House;
}

HouseBuilder* ConcreteHouseBuilder::buildFloor() {
    mHouse->setFloorType("concrete");
    return this;
}

HouseBuilder* ConcreteHouseBuilder::buildWall() {
    mHouse->setWallType("concrete");
    return this;
}

HouseBuilder* ConcreteHouseBuilder::buildRoof() {
    mHouse->setRoofType("concrete");
    return this;
}

House* ConcreteHouseBuilder::build() {
    return mHouse;
}
