#include <iostream>

class Base {
private:
	int m_value;
 
public:
	Base(int value)
		: m_value(value)
	{}
 
	int getValue() { return m_value; }
};
 
class Derived : public Base {
public:
	Derived(int value)
		: Base(value)
	{}
 
	int getValue() = delete;
};
 
int main()
{
	Derived derived(7);
 
	// std::cout << derived.getValue(); // Error
    std::cout << static_cast<Base>(derived).getValue();
 
	return 0;
}