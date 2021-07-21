#include <iostream>
#include <vector>

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  std::string name;
  Color color;
  Size size;
};

using Items = std::vector<Product *>;

struct ProductFilter {
  static Items by_color(Items items, const Color &color) {
    Items result;
    for (auto &item : items) {
      if (item->color == color)
        result.push_back(item);
    }
    return result;
  }
  static Items by_size(Items items, const Size &size) {
    Items result;
    for (auto &item : items) {
      if (item->size == size)
        result.push_back(item);
    }
    return result;
  }
  static Items by_color_and_size(Items items, const Color &color,
                                 const Size &size) {
    Items result;
    for (auto &item : items) {
      if (item->color == color && item->size == size)
        result.push_back(item);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  const Items all_prod{new Product{"Apple", Color::green, Size::small},
                       new Product{"Tree", Color::green, Size::large},
                       new Product{"House", Color::blue, Size::large}};

  for (auto &p : ProductFilter::by_color(all_prod, Color::green)) {
    std::cout << p->name << " is green" << std::endl;
  }

  for (auto &p :
       ProductFilter::by_color_and_size(all_prod, Color::green, Size::large)) {
    std::cout << p->name << " is green & large" << std::endl;
  }
  return 0;
}
