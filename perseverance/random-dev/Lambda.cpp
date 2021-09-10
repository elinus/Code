#include <iostream>
#include <functional>

struct Test {
    int operator()(int i) {
        std::cout << __func__ << std::endl;
        return i + 100;
    }
};

int main(int argc, char const *argv[])
{
    Test t;
    std::cout << t(0) << std::endl;
    std::cout << "\n\n";
    auto lam = [](int i) {
        std::cout << __func__ << std::endl;
        return i + 100;
    };
    return 0;
}
