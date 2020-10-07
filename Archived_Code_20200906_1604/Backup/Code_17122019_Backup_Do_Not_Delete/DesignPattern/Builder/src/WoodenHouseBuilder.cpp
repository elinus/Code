#include "WoodenHouseBuilder.h"

WoodenHouseBuilder::WoodenHouseBuilder() { house_ = new House(); }

WoodenHouseBuilder::~WoodenHouseBuilder() { delete house_; }

HouseBuilder *WoodenHouseBuilder::buildFloor() {
  house_->setFloorType("Wood");
  return this;
}

HouseBuilder *WoodenHouseBuilder::buildWall() {
  house_->setWallType("Wood");
  return this;
}

HouseBuilder *WoodenHouseBuilder::buildRoof() {
  house_->setRoofType("Wood");
  return this;
}

House *WoodenHouseBuilder::build() { return house_; }
