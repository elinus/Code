// $ g++ -c VPtrTest.cpp
// $ nm VPtrTest.o | c++filt
#include <iostream>

class A {};

class B { 
    int i;
    void print(){}
};

class C {
    int i;
    virtual void print(){}
};

class D : public C {
    int i;
    void print(){}
};

int main(int argc, char *argv[])
{
    A a;
    B b;
    C c;
    D d;
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(d) << std::endl;
    return 0;
}

