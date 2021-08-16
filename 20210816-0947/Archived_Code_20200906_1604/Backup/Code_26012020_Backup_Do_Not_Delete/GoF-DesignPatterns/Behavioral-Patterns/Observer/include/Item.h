#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

class Item {
    public:
        const std::string mName;
        const double mPrice;
        Item(std::string name, double price);
};

#endif /* __ITEM_H__ */
