#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <string>
#include <sstream>

class House {
    private:
        std::string mFloorType;
        std::string mWallType;
        std::string mRoofType;
    public:
        std::string getFloorType();
        void setFloorType(std::string);
        std::string getWallType();
        void setWallType(std::string);
        std::string getRoofType();
        void setRoofType(std::string);
        std::string toString();
};

#endif /* __HOUSE_H__ */
