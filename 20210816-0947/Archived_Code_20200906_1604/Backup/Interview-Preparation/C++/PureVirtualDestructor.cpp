#include <iostream>

class Base {
    public:
        virtual ~Base() = 0;
};

Base::~Base() {
    std::cout << "Pure virtual destructor!\n";
}

class Derived : public Base {
    public:
        ~Derived() {
            std::cout << "Derived destrcutor.\n";
        }
};

int main (int argc, char *argv[]) {
    
    Base *bP = new Derived;
    delete bP;    
    return 0;
}

