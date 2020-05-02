#include <iostream>
#include <cmath>

int main(int argc, char const *argv[]) {
    std::cout << "Net gain:=> " << pow(1.01, 365) << std::endl;
    std::cout << "Amount left:=> " << pow(0.99, 365) << std::endl;
    return 0;
}

