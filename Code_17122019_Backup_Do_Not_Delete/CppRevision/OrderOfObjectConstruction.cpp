#include <iostream>

class A {
    public:
        A() { std::cout << "A\n"; }
        ~A() { std::cout << "~A\n"; }
};

class B : public A {
    public:
        B() { std::cout << "B\n"; }
        ~B() { std::cout << "~B\n"; }
};

class C : public B {
    public:
        C() { std::cout << "C\n"; }
        ~C() { std::cout << "~C\n"; }
};

class D : public C {
    public:
        D() { std::cout << "D\n"; }
        ~D() { std::cout << "~D\n"; }
};

int main() {
    std::cout << "##### A #####\n";
    A a;
    std::cout << "##### B #####\n";
    B b;
    std::cout << "##### C #####\n";
    C c;
    std::cout << "##### D #####\n";
    D d;
}
