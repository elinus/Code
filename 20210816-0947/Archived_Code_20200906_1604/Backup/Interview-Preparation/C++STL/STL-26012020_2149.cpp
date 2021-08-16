#include <iostream>
#include <string>
#include <algorithm>

int main (int argc, char *argv[]) {
    std::string str("Hello World!!");
    std::cout << str << "\n";

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    std::cout << str << "\n";
    return 0;
}

