#include "ConcreteHouseBuilder.h"

ConcreteHouseBuilder::ConcreteHouseBuilder() { house_ = new House(); }

ConcreteHouseBuilder::~ConcreteHouseBuilder() { delete house_; }

HouseBuilder *ConcreteHouseBuilder::buildFloor() {
  house_->setFloorType("Concrete");
  return this;
}

HouseBuilder *ConcreteHouseBuilder::buildWall() {
  house_->setWallType("Concrete");
  return this;
}

HouseBuilder *ConcreteHouseBuilder::buildRoof() {
  house_->setRoofType("Concrete");
  return this;
}

House *ConcreteHouseBuilder::build() { return house_; }
