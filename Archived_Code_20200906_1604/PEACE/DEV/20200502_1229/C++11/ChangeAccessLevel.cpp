#include <iostream>
 
class Base {
private:
    int m_value;
 
public:
    Base(int value)
        : m_value(value)
    {}
 
protected:
    void printValue() { std::cout << m_value; }
};

class Derived : public Base {
public:
    Derived(int value)
        : Base(value)
    {}
 
    using Base::printValue; 
};

int main()
{
    Derived derived(7);
    derived.printValue();
    return 0;
}