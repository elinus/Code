#ifndef __HOUSEBUILDER_H__
#define __HOUSEBUILDER_H__

#include "House.h"

class HouseBuilder {
public:
    virtual HouseBuilder* buildFloor() = 0;
    virtual HouseBuilder* buildWall() = 0;
    virtual HouseBuilder* buildRoof() = 0;
    virtual House* build() = 0;
};

#endif /* __HOUSEBUILDER_H__ */
