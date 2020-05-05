#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
    string name;
    Color color;
    Size size;
};

struct ProductFilter {
    typedef vector<Product*> Items;
    Items by_color(Items items, const Color color) {
        Items result;
        for (auto& i: items) {
            if (i->color == color)
                result.push_back(i);
        }
        return result;
    }
    
    Items by_size(Items items, const Size size) {
        Items result;
        for (auto& i: items) {
            if (i->size == size)
                result.push_back(i);
        }
        return result;
    }
    
    Items by_size_and_color(Items items, const Size size, const Color color) {
        Items result;
        for (auto& i: items) {
            if (i->size == size && i->color == color)
                result.push_back(i);
        }
        return result;
    }
};

template <typename T> struct AndSpecification;

template <typename T> struct Specification {
    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0;
};

template <typename T> AndSpecification<T> operator&&(
        const Specification<T>& first, const Specification<T>& second) {
    return { first, second };
}

template <typename T> struct Filter {
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product> {
    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override {
        vector<Product*> result;
        for (auto& p: items) {
            if (spec.is_satisfied(p))
                result.push_back(p);
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product> {
    Color color;
    ColorSpecification(Color color) : color(color) {}
    bool is_satisfied(Product* item) const override {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product> {
    Size size;
    SizeSpecification(Size size) : size(size) {}
    bool is_satisfied(Product* item) const override {
        return item->size == size;
    }
};

template <typename T> struct AndSpecification : Specification<T> {
    const Specification<T>& first;
    const Specification<T>& second;
    AndSpecification(const Specification<T>& first, const Specification<T>& second)
        : first(first), second(second) {}
    bool is_satisfied(T *item) const override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

int main (int argc, char *argv[]) {
    Product apple {"Apple", Color::green, Size::small};
    Product tree {"Tree", Color::green, Size::large};
    Product house {"House", Color::blue, Size::large};
    
    const vector<Product*> all_prod {&apple, &tree, &house};
    ProductFilter pf;
    for(auto i: pf.by_color(all_prod, Color::green)) {
        cout << i->name << endl;
    }

    BetterFilter bf;
    ColorSpecification green(Color::green);
    auto green_things = bf.filter(all_prod, green);
    for (auto& x: green_things) {
        cout << x->name << " is green\n";
    }

    SizeSpecification large(Size::large);
    AndSpecification<Product> green_and_large(green, large);
    auto spec = green && large;
    for (auto& x: bf.filter(all_prod, spec)) {
        cout << x->name << " is green and large\n";
    }
    
    return 0;
}
