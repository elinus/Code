#ifndef __CONCRETEHOUSEBUILDER_H__
#define __CONCRETEHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"
#include <string>

class ConcreteHouseBuilder : public HouseBuilder {
public:
  ConcreteHouseBuilder();
  ~ConcreteHouseBuilder() override;
  HouseBuilder *buildFloor() override;
  HouseBuilder *buildWall() override;
  HouseBuilder *buildRoof() override;
  House *build() override;

private:
  House *house_;
};

#endif /* __CONCRETEHOUSEBUILDER_H__ */
