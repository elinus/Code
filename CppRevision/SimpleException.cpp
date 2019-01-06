#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    try {
        throw 8;
    } catch (int e) {
        std::cout << "Exception thrown: " << std::to_string(e) << std::endl;
    }
    return 0;
}

