#include <iostream>
#include <string>

using namespace std;

class Int {
    int x;
    public:
    Int(int x = 0): x(x) {
        std::cout << "Conversion constructor\n";
    }
    operator std::string () {
        std::cout << "Conversion operator\n";
        return std::to_string(x);
    }
};

class Base {};
class Derived : private Base {};
class Derived1 : public Base {};
class Derived2 : public Base {};

int main(int argc, char const *argv[]) {
    // 1
    float f = 14.15;
    int i;
    
    i = f;
    std::cout << i << "\n";
    
    i = static_cast<int>(f);
    std::cout << i << "\n";

    // 2
    Int obj(14);
    std::string str1 = obj;
    obj = 20;

    std::string str2 = static_cast<std::string>(obj);
    obj = static_cast<Int>(24);

    // 3
    char c; // 1 Byte
    int *p = (int *)&c; // 4 Byte
    *p = 14; // Pass at compile time
    //int *ip = static_cast<int*>(&c); // Compile time error
    // error: static_cast from 'char *' to 'int *' is not allowed
    
    // 4
    Derived d0;
    Base *bp0 = (Base *)&d0; // Allowed at compile time
    //bp0 = static_cast<Base *>(&d0); // error: cannot cast 'Derived' to its private base class 'Base'

    // 5
    Derived1 d1;
    Derived2 d2;
    Base *b1p = static_cast<Base *>(&d1);
    Base *b2p = static_cast<Base *>(&d2);
    Derived1 *d1p = static_cast<Derived1 *>(b1p);
    Derived2 *d2p = static_cast<Derived2 *>(b2p);

    // 6
    int v = 14;
    void *vp;
    vp = static_cast<void *>(&v);
    int *ip = static_cast<int *>(vp);
    return 0;
}

