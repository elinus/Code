#include <iostream>
#include <vector>

struct Item {
  static int constructor;
  static int copyConstrctor;
  static int destructor;
  Item() { constructor++; }
  ~Item() { destructor++; }
  Item(const Item &other) { copyConstrctor++; }
};

int Item::constructor = 0;
int Item::copyConstrctor = 0;
int Item::destructor = 0;

class ItemFactory {
public:
  static std::vector<Item> getItemObjects(int count) {
    std::vector<Item> vecOfItems;
    vecOfItems.assign(count, Item());
    // vecOfItems.reserve(count);
    // for (int var = 0; var < count; ++var) {
    //   vecOfItems.push_back(Item());
    // }
    return vecOfItems;
  }
};

int main(int argc, char const *argv[]) {
  int count = 10000;
  std::vector<Item> vecOfItems = ItemFactory::getItemObjects(count);

  std::cout << "Total Item Objects constructed = "
            << (Item::constructor + Item::copyConstrctor) << std::endl;
  std::cout << "Constructor called  " << Item::constructor << " times"
            << std::endl;
  std::cout << "Copy Constructor called  " << Item::copyConstrctor << " times"
            << std::endl;
  std::cout << "Total Item Objects destructed = " << Item::destructor
            << std::endl;
  return 0;
}
