#ifndef __WOODENHOUSEBUILDER_H__
#define __WOODENHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"

class WoodenHouseBuilder : public HouseBuilder {
private:
    House *mHouse;
public:
    WoodenHouseBuilder();
    HouseBuilder* buildFloor();
    HouseBuilder* buildWall();
    HouseBuilder* buildRoof();
    House* build();
};

#endif /* __WOODENHOUSEBUILDER_H__ */
