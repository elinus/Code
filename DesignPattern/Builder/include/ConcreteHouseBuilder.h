#ifndef __CONCRETEHOUSEBUILDER_H__
#define __CONCRETEHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"
#include <string>

class ConcreteHouseBuilder : public HouseBuilder {
public:
  ConcreteHouseBuilder();
  ~ConcreteHouseBuilder();
  HouseBuilder *buildFloor();
  HouseBuilder *buildWall();
  HouseBuilder *buildRoof();
  House *build();

private:
  House *house_;
};

#endif /* __CONCRETEHOUSEBUILDER_H__ */
