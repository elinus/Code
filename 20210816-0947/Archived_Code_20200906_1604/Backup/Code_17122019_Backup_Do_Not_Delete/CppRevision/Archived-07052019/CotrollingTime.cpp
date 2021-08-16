#include <iostream>

class Foo {
    public:
    Foo() {
        std::cout << "Foo() called" << std::endl;
    }
    ~Foo() {
        std::cout << "~Foo() called" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Foo *fooPtr;
    new(fooPtr) Foo();
    fooPtr->~Foo();
    return 0;
}
