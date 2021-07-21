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

template <typename T> struct Specification {
  virtual ~Specification() = default;
  virtual bool is_satisfied(T *prod) const = 0;
};

struct ColorSpecification : Specification<Product> {
  Color color;
  ColorSpecification(const Color &color) : color{color} {}
  bool is_satisfied(Product *prod) const override {
    return prod->color == color;
  }
};

struct SizeSpecification : Specification<Product> {
  Size size;
  SizeSpecification(const Size &size) : size{size} {}
  bool is_satisfied(Product *prod) const override { return prod->size == size; }
};

template <typename T> struct Filter {
  virtual std::vector<T *> filter(std::vector<T *> items,
                                  const Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product> {
  std::vector<Product *> filter(std::vector<Product *> items,
                                const Specification<Product> &spec) override {
    std::vector<Product *> result;
    for (auto &prod : items) {
      if (spec.is_satisfied(prod)) {
        result.push_back(prod);
      }
    }
    return result;
  }
};

template <typename T> struct AndSpecification : Specification<T> {
  const Specification<T> &first;
  const Specification<T> &second;
  AndSpecification(const Specification<T> &first,
                   const Specification<T> &second)
      : first{first}, second{second} {}
  bool is_satisfied(T *prod) const override {
    return first.is_satisfied(prod) && second.is_satisfied(prod);
  }
};

int main(int argc, char const *argv[]) {
  const Items all_prod{new Product{"Apple", Color::green, Size::small},
                       new Product{"Tree", Color::green, Size::large},
                       new Product{"House", Color::blue, Size::large}};

  BetterFilter bf;
  for (auto &p : bf.filter(all_prod, ColorSpecification(Color::green))) {
    std::cout << p->name << " is green" << std::endl;
  }

  for (auto &p :
       bf.filter(all_prod, AndSpecification<Product>(ColorSpecification(Color::green),
                                            SizeSpecification(Size::large)))) {
    std::cout << p->name << " is green & large" << std::endl;
  }
  return 0;
}
