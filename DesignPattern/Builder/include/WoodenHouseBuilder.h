#ifndef __WOODENHOUSEBUILDER_H__
#define __WOODENHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"
#include <string>

class WoodenHouseBuilder : public HouseBuilder {
public:
  WoodenHouseBuilder();
  ~WoodenHouseBuilder();
  HouseBuilder *buildFloor();
  HouseBuilder *buildWall();
  HouseBuilder *buildRoof();
  House *build();

private:
  House *house_;
};

#endif /* __WOODENHOUSEBUILDER_H__ */
