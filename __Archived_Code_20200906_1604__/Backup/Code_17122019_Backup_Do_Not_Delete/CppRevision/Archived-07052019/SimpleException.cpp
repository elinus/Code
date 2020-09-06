#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    try {
        throw 14;
    } catch (int e) {
        std::cout << "Int exception thrown: " << std::to_string(e) << std::endl;
    }
    return 0;
}