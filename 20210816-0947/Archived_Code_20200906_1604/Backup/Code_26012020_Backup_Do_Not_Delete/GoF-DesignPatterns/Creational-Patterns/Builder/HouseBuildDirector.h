#ifndef __HOUSEBUILDDIRECTOR_H__
#define __HOUSEBUILDDIRECTOR_H__

#include "House.h"
#include "HouseBuilder.h"

class HouseBuildDirector {
private:
    HouseBuilder *mBuilder;
public:
    HouseBuildDirector(HouseBuilder *builder);
    House* construct();
};

#endif /* __HOUSEBUILDDIRECTOR_H__ */
