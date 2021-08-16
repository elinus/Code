#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class COLOR { RED, GREEN, BLUE };
enum class SIZE { SMALL, MEDIUM, LARGE };

struct Product {
	string m_name;
	COLOR m_color;
	SIZE m_size;
};

using Items = vector<Product*>;

template <typename T>
struct Specification {
	virtual ~Specification() = default;
	virtual bool is_statisfied(T* item) const = 0;
};

struct ColorSpecification : Specification<Product> {
	COLOR color;
	ColorSpecification(COLOR color) : color{ color} {}
	bool is_statisfied(Product* item) const {
		return item->m_color == color;
	}
};

struct SizeSpecification : Specification<Product> {
	SIZE size;
	SizeSpecification(SIZE size) : size{ size } {}
	bool is_statisfied(Product* item) const {
		return item->m_size == size;
	}
};

template <typename T>
struct Filter {
	virtual vector<T*> filter(vector<T*> items, const Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product> {
	vector<Product*> filter(vector<Product*> items, const Specification<Product>& spec) {
		vector<Product*> result;
		for (auto& item : items) {
			if (spec.is_statisfied(item)) result.push_back(item);
		}
		return result;
	}
};

template <typename T>
struct AndSpecification : Specification<T> {
	const Specification<T>& first;
	const Specification<T>& second;
	AndSpecification(const Specification<T>& first, const Specification<T>& second)
		: first(first), second(second) {
	}
	bool is_statisfied(T* item) const {
		return first.is_statisfied(item) && second.is_statisfied(item);
	}
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T>& first, const Specification<T>& second) {
	return { first, second };
}

//struct ProductFilter {
//	static Items by_color(Items items, const COLOR color) {
//		Items result;
//		for (auto& item : items) {
//			if (item->m_color == color) result.push_back(item);
//		}
//		return result;
//	}
//	static Items by_size(Items items, const SIZE size) {
//		Items result;
//		for (auto& item : items) {
//			if (item->m_size == size) result.push_back(item);
//		}
//		return result;
//	}
//	static Items by_size_and_color(Items items, const SIZE size, const COLOR color) {
//		Items result;
//		for (auto& item : items) {
//			if (item->m_size == size && item->m_color == color) result.push_back(item);
//		}
//		return result;
//	}
//};

//main_20210201_1440
int main_20210201_1440() {

	const Items all_items{
		new Product{"Apple", COLOR::GREEN, SIZE::SMALL},
		new Product{"Tree", COLOR::GREEN, SIZE::LARGE},
		new Product{"House", COLOR::BLUE, SIZE::LARGE},
	};
	BetterFilter bf1;
	for (auto& x : bf1.filter(all_items, ColorSpecification(COLOR::GREEN)))
		cout << x->m_name << " is green\n";

	auto green_things = ColorSpecification{ COLOR::GREEN };
	auto large_things = SizeSpecification{ SIZE::LARGE };
	BetterFilter bf2;
	for (auto& x : bf2.filter(all_items, green_things&& large_things))
		cout << x->m_name << " is green and large\n\n";
	
	auto and_spec = SizeSpecification{ SIZE::LARGE } && ColorSpecification{COLOR::BLUE};
	for (auto& x : bf2.filter(all_items, and_spec))
		cout << x->m_name << " is green and large\n";
	//for (auto& p : ProductFilter::by_color(all_items, COLOR::GREEN)) {
	//	cout << p->m_name << " is green\n";
	//}
	//cout << "\n\n";
	//for (auto& p : ProductFilter::by_size_and_color(all_items, SIZE::LARGE, COLOR::GREEN)) {
	//	cout << p->m_name << " is large & green\n";
	//}
	return 0;
}