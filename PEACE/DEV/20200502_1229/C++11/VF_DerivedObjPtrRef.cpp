#include <iostream>
#include <string_view>
#include <string>

class Base {
    protected:
    int m_Value;
    public:
    Base(int value)
        : m_Value(value)
    {}
    virtual std::string_view getName() const {
        return "Base";
    }
    int getValue() const {
        return m_Value;
    }
};

class Derived : public Base {
    public:
    Derived(int value) : Base { value }
    {};
    virtual std::string_view getName() const {
        return "Derived";
    }
    int getDoubleValue() {
        return 2 * m_Value;
    }
};

int main(int argc, char const *argv[])
{
    Derived derived { 14 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    Derived &rDerived { derived };
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';
    Derived *pDerived { &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    Base &rBase { derived };
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    Base *pBase { &derived };
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';
    return 0;
}
