#include <iostream>

class Base {
    public:
        Base() {
            std::cout << "Base()\n";
        }
        virtual ~Base() {
            std::cout << "~Base()\n";
        }
};

class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived()\n";
        }
        ~Derived() {
            std::cout << "~Derived()\n";
        }
};

int main (int argc, char *argv[]) {
    
    Base *bP = new Derived();
    delete bP;

    return 0;
}

