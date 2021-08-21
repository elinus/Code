#include <iostream>

template <typename T>
struct Property {
	T m_value;
	Property(const T initial_value) {
		*this = initial_value;
	}
	operator T() {
		return m_value;
	}
	T operator = (T new_value) {
		return m_value = new_value;
	}
};

struct Creature {
	Property<int32_t> m_strength{ 0 };
	Property<int32_t> m_agility{ 0 };
};

//int main() {
//	Creature creature;
//	creature.m_agility = 20;
//	std::cout << "creature = "  << creature.m_agility << std::endl;
//	return 0;
//}