#ifndef __CONCRETEHOUSEBUILDER_H__
#define __CONCRETEHOUSEBUILDER_H__

#include "House.h"
#include "HouseBuilder.h"

class ConcreteHouseBuilder : public HouseBuilder {
private:
    House *mHouse;
public:
    ConcreteHouseBuilder();
    HouseBuilder* buildFloor();
    HouseBuilder* buildWall();
    HouseBuilder* buildRoof();
    House* build();
};

#endif /* __CONCRETEHOUSEBUILDER_H__ */
