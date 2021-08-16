#include <iostream>

class Base {
    private:
    void print() {
        std::cout << "Base :: print()\n";
    }
    public:
};

class Derived1 : public Base {
    public:
    void print() {
        std::cout << "Derived1 :: print\n";
    }
};

class Derived2 : public Derived1 {
    public:
    void print() {
        Derived1::print();
        std::cout << "Derived2 :: print\n";
    }
};

int main(int argc, char const *argv[])
{
    Derived1 derived1;
    derived1.print();

    Derived2 derived2;
    derived2.print();
    return 0;
}
