#include <iostream>
#include <exception>

using namespace std;

class Base {
    public:
        virtual void print() {
            std::cout << "Base\n"; 
        }
};

class Derived1 : public Base {
    public:
        virtual void print() {
            std::cout << "Derived1\n"; 
        }
};

class Derived2 : public Base {
    public:
        virtual void print() {
            std::cout << "Derived2\n"; 
        }
};

int main(int argc, char const *argv[]) {
    Derived1 d1p;
    Base *bp = dynamic_cast<Base *>(&d1p);
    if (bp != nullptr) {
        std::cout << "Derived to Base typecasting success!.\n";
    }

    Derived2 *d2p = dynamic_cast<Derived2 *>(bp);
    if (d2p == nullptr) {
        std::cout << "Derived2 to Derived1 typecasting fail!.\n";
    }

    Derived1 *d1 = dynamic_cast<Derived1 *>(bp);
    if (d1 != nullptr) {
        std::cout << "d1 is not null.\n";
    }

    try {
        Derived2 &r1 = dynamic_cast<Derived2&>(d1p);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

