#include "House.h"

std::string House::getFloorType() {
    return mFloorType;
}

void House::setFloorType(std::string floorType) {
    mFloorType = floorType;
}

std::string House::getWallType() {
    return mWallType;
}

void House::setWallType(std::string wallType) {
    mWallType = wallType;
}

std::string House::getRoofType() {
    return mRoofType;
}

void House::setRoofType(std::string roofType) {
    mRoofType = roofType;
}

std::string House::toString() {
    std::stringstream ss;
    ss << "\nConstructing House\n  FloorType: " << mFloorType << "\n  WallType: " << mWallType << "\n  RoofType: " << mRoofType << "\n";
    return ss.str();
}
