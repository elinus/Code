#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

int main (int argc, char *argv[]) {
    std::ifstream input("RandomNumbers.txt");
    std::copy(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>(), 
            std::ostreambuf_iterator<char>(std::cout));
    return 0;
}

