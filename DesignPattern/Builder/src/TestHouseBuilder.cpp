#include "ConcreteHouseBuilder.h"
#include "House.h"
#include "HouseBuildDirector.h"
#include "HouseBuilder.h"
#include "WoodenHouseBuilder.h"

int main() {
  HouseBuilder *builder = new ConcreteHouseBuilder();
  HouseBuildDirector *director = new HouseBuildDirector(builder);
  std::cout << director->construct() << std::endl;

  builder = new WoodenHouseBuilder();
  director = new HouseBuildDirector(builder);
  std::cout << director->construct() << std::endl;

  return 0;
}
