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

struct ProductFilter {
	static Items by_color(Items items, const COLOR color) {
		Items result;
		for (auto& item : items) {
			if (item->m_color == color) result.push_back(item);
		}
		return result;
	}
	static Items by_size(Items items, const SIZE size) {
		Items result;
		for (auto& item : items) {
			if (item->m_size == size) result.push_back(item);
		}
		return result;
	}
	static Items by_size_and_color(Items items, const SIZE size, const COLOR color) {
		Items result;
		for (auto& item : items) {
			if (item->m_size == size && item->m_color == color) result.push_back(item);
		}
		return result;
	}
};

//main_20210201_1424
int main_20210201_1424() {

	const Items all_items{
		new Product{"Apple", COLOR::GREEN, SIZE::SMALL},
		new Product{"Tree", COLOR::GREEN, SIZE::LARGE},
		new Product{"House", COLOR::BLUE, SIZE::LARGE},
	};
	for (auto& p : ProductFilter::by_color(all_items, COLOR::GREEN)) {
		cout << p->m_name << " is green\n";
	}
	cout << "\n\n";
	for (auto& p : ProductFilter::by_size_and_color(all_items, SIZE::LARGE, COLOR::GREEN)) {
		cout << p->m_name << " is large & green\n";
	}
	return 0;
}