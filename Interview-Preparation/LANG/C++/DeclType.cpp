#include <iostream>

template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a+b) {
    return a+b;
}

int main (int argc, char *argv[]) {
    std::cout << add(1.5, 1) << std::endl;
    std::cout << add(1, 1.5) << std::endl;
    return 0;
}

