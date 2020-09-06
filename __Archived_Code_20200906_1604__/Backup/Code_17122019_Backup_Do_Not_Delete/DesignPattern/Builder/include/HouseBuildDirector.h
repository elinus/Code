#ifndef __HOUSEBUILDDIRECTOR_H__
#define __HOUSEBUILDDIRECTOR_H__

#include "House.h"
#include "HouseBuilder.h"

class HouseBuildDirector {
public:
  HouseBuildDirector(HouseBuilder *houseBuilder);
  House *construct();

private:
  HouseBuilder *houseBuilder;
};

#endif /* __HOUSEBUILDDIRECTOR_H__ */
