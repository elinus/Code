#ifndef __WOODENHOUSEBUILDER_H__
#define __WOODENHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"
#include <string>

class WoodenHouseBuilder : public HouseBuilder {
public:
  WoodenHouseBuilder();
  ~WoodenHouseBuilder() override;
  HouseBuilder *buildFloor() override;
  HouseBuilder *buildWall() override;
  HouseBuilder *buildRoof() override;
  House *build() override;

private:
  House *house_;
};

#endif /* __WOODENHOUSEBUILDER_H__ */
