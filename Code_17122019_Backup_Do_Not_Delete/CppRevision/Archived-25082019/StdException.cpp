#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

int main(int argc, char const *argv[]) {
    try {
        std::string s;
        s.resize(-1);
    } catch (std::exception &e) {
        std::cerr << "Exception:=> " << e.what() << std::endl;
    }

    try {
        throw std::runtime_error("Bad things happened!");
    } catch (std::exception &e) {
        std::cerr << "Exception:=> " << e.what() << std::endl;
    }
    return 0;
}

