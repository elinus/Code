#include <iostream>
#include <typeinfo>

class Base {};

int main (int argc, char *argv[]) {
    auto i = 14;
    auto d = 14.20;
    auto bp = new Base();
    std::cout << typeid(i).name() << "\n";
    std::cout << typeid(d).name() << "\n";
    std::cout << typeid(bp).name() << "\n";
    return 0;
}

