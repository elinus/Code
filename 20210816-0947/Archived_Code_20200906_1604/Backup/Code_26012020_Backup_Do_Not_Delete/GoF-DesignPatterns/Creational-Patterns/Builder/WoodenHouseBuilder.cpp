#include "WoodenHouseBuilder.h"

WoodenHouseBuilder::WoodenHouseBuilder() {
    mHouse = new House;
}

HouseBuilder* WoodenHouseBuilder::buildFloor() {
    mHouse->setFloorType("wood");
    return this;
}

HouseBuilder* WoodenHouseBuilder::buildWall() {
    mHouse->setWallType("wood");
    return this;
}

HouseBuilder* WoodenHouseBuilder::buildRoof() {
    mHouse->setRoofType("wood");
    return this;
}

House* WoodenHouseBuilder::build() {
    return mHouse;
}
