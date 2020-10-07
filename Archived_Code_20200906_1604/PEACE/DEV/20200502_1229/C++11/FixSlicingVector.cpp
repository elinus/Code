#include <iostream>
#include <vector>
#include <functional>

class Base
{
protected:
    int m_value{};
 
public:
    Base(int value)
        : m_value{ value }
    {
    }
 
    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
 
class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }
 
    virtual const char* getName() const { return "Derived"; }
};
 
int main()
{
    std::vector<std::reference_wrapper<const Base>> v{};
    Base base { 5 }; 
    Derived derived { 6 };
	v.push_back(base); // add a Base object to our vector
	v.push_back(derived); // add a Derived object to our vector
 
        // Print out all of the elements in our vector
	for (const auto& element : v)
		std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';
 
	return 0;

}