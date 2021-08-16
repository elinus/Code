#include <iostream>

class Base {
    public:
    virtual Base* getThis() {
        std::cout << "called Base::getThis()\n";
        return this;
    }
    void printType() {
        std::cout << "returned a Base\n";
    }
};

class Derived : public Base {
    public:
    virtual Derived* getThis() {
        std::cout << "called Derived::getThis()\n";
        return this;
    }
    void printType() {
        std::cout << "returned a Derived\n";
    }
};

int main(int argc, char const *argv[])
{
    Derived derived;
    Base *pB = &derived;
    derived.getThis()->printType();
    pB->getThis()->printType();
    return 0;
}
