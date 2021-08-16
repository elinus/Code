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

struct Specification {
  virtual ~Specification() = default;
  virtual bool is_satisfied(Product *prod) const = 0;
};

struct ColorSpecification : Specification {
  Color color;
  ColorSpecification(const Color &color) : color{color} {}
  bool is_satisfied(Product *prod) const override {
    return prod->color == color;
  }
};

struct SizeSpecification : Specification {
  Size size;
  SizeSpecification(const Size &size) : size{size} {}
  bool is_satisfied(Product *prod) const override { return prod->size == size; }
};

struct Filter {
  virtual std::vector<Product *> filter(std::vector<Product *> items,
                                        const Specification &spec) = 0;
};

struct BetterFilter : Filter {
  std::vector<Product *> filter(std::vector<Product *> items,
                                const Specification &spec) override {
    std::vector<Product *> result;
    for (auto &prod : items) {
      if (spec.is_satisfied(prod)) {
        result.push_back(prod);
      }
    }
    return result;
  }
};

struct AndSpecification : Specification {
  const Specification &first;
  const Specification &second;
  AndSpecification(const Specification &first, const Specification &second)
      : first{first}, second{second} {}
  bool is_satisfied(Product *prod) const override {
    return first.is_satisfied(prod) && second.is_satisfied(prod);
  }
};

// struct ProductFilter {
//   static Items by_color(Items items, const Color &color) {
//     Items result;
//     for (auto &item : items) {
//       if (item->color == color)
//         result.push_back(item);
//     }
//     return result;
//   }
//   static Items by_size(Items items, const Size &size) {
//     Items result;
//     for (auto &item : items) {
//       if (item->size == size)
//         result.push_back(item);
//     }
//     return result;
//   }
//   static Items by_color_and_size(Items items, const Color &color,
//                                  const Size &size) {
//     Items result;
//     for (auto &item : items) {
//       if (item->color == color && item->size == size)
//         result.push_back(item);
//     }
//     return result;
//   }
// };

int main(int argc, char const *argv[]) {
  const Items all_prod{new Product{"Apple", Color::green, Size::small},
                       new Product{"Tree", Color::green, Size::large},
                       new Product{"House", Color::blue, Size::large}};

  //   for (auto &p : ProductFilter::by_color(all_prod, Color::green)) {
  //     std::cout << p->name << " is green" << std::endl;
  //   }
  BetterFilter bf;
  for (auto &p : bf.filter(all_prod, ColorSpecification(Color::green))) {
    std::cout << p->name << " is green" << std::endl;
  }

  //   for (auto &p :
  //        ProductFilter::by_color_and_size(all_prod, Color::green,
  //        Size::large)) {
  //     std::cout << p->name << " is green & large" << std::endl;
  //   }
  for (auto &p :
       bf.filter(all_prod, AndSpecification(ColorSpecification(Color::green),
                                            SizeSpecification(Size::large)))) {
    std::cout << p->name << " is green & large" << std::endl;
  }
  return 0;
}
