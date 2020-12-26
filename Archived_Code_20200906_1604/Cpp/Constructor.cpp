#include <iostream>

class A {
    public:
        A() { std::cout << "A\n"; }
};

class B {
    private:
        A m_a; // B contains A as a member variable

    public:
        B() { std::cout << "B\n"; }
};

int main() {
    B b;
    return 0;
}
