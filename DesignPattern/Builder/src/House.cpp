#include "House.h"

std::string House::getFloorType() { return floor_; }

std::string House::getWallType() { return wall_; }

std::string House::getRoofType() { return roof_; }

void House::setFloorType(std::string floor) { floor_ = floor; }

void House::setWallType(std::string wall) { wall_ = wall; }

void House::setRoofType(std::string roof) { roof_ = roof; }

std::ostream &operator<<(std::ostream &out, House *house) {
  out << "Constructing House\n";
  out << "\tFloor type: " << house->floor_ << "\n";
  out << "\tWall type: " << house->wall_ << "\n";
  out << "\tRoof type: " << house->roof_ << "\n";
  return out;
}
