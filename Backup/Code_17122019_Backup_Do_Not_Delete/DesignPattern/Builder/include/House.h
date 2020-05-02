#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <iostream>
#include <string>

class House {
public:
  std::string getFloorType();
  std::string getWallType();
  std::string getRoofType();
  void setFloorType(std::string floor_);
  void setWallType(std::string wall_);
  void setRoofType(std::string roof_);
  friend std::ostream &operator<<(std::ostream &out, House *house);

private:
  std::string floor_;
  std::string wall_;
  std::string roof_;
};

#endif /* __HOUSE_H__ */
