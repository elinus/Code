#include <iostream>

class Base {
    public:
        Base() {}
};

class Derived : public Base {
    public: 
        Derived() {}
};

int main(int argc, char const *argv[]) {
    try {
        throw Derived();
    } catch (Base &be) {
        std::cerr << "Base type exception!" << std::endl;
    } catch (Derived &de) {
        std::cerr << "Derived type exception!" << std::endl;
    }
    return 0;
}

