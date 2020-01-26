#include <iostream>

//class Base final { // error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derived’
class Base {
    public:
        //virtual void foo() final { // error: overriding final function ‘virtual void Base::foo()’
        virtual void foo() {
            std::cout << "Base - foo" << std::endl;
        }
};

class Derived : public Base {
    public:
        void foo() {
            std::cout << "Derived - foo" << std::endl;
        }
};

int main (int argc, char *argv[]) {
    Derived d;
    Base &b = d;
    b.foo();
    return 0;
}

