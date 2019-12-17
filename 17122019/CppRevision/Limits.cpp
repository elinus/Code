#include <iostream>
#include <climits>
#include <limits>

int main(int argc, char const *argv[]) {
    
    /* climits */
    std::cout << "INT_MAX = " << INT_MAX << "\n";
    std::cout << "INT_MIN = " << INT_MIN << "\n";
    std::cout << "UINT_MAX = " << UINT_MAX << "\n";
    std::cout << "CHAR_MAX = " << CHAR_MAX << "\n";
    std::cout << "CHAR_MIN = " << CHAR_MIN << "\n";
    std::cout << "LLONG_MAX = " << LLONG_MAX << "\n";
    std::cout << "LLONG_MIN = " << LLONG_MIN << "\n";
    
    /* limits */
    std::cout << "minimum value for int = " << std::numeric_limits<int>::min() << "\n";
    std::cout << "maximum value for int = " << std::numeric_limits<int>::max() << "\n";

    return 0;
}

