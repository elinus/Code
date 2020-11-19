#include <iostream>

// {{ Implicit Conversion
struct A {
    A() {
        std::cout << "A()\n";
    }
};

struct B : A {
    B(A a) {
        std::cout << "B()\n";
    }
};

// Implicit Conversion }}

class Mammal {};
class Human : public Mammal {
    public:
        virtual void scream() {
            std::cout << "Mom!\n";
        }
};

int main (int argc, const char *argv[]) {
    A a;
    std::cout << __func__ << " :: A object created!\n";
    B b = a;

    Human *h1 = new Human; // Pointer to object of derived type
    Mammal *m1 = static_cast<Mammal *>(h1); // cast it to pointer to base type. static_cast is unnecessary.
    //Human *h2 = m1;
    // Errors
    // clang++  :: error: cannot initialize a variable of type 'Human *' with an lvalue of type 'Mammal *'
    // g++      :: error: invalid conversion from ‘Mammal*’ to ‘Human*’ [-fpermissive]
 
    Mammal *m2 = static_cast<Human *>(m1); // cast back to pointer to dervied type.

    Mammal *m3 = new Mammal; // Mammal that is not human!
    Human *h3 = static_cast<Human *>(m3); // OK so far
    h3->scream();
    return 0;
}

