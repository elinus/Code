#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

int foo(int x, int y) { return x + 2 * y; }

struct Bar {
    int operator ()(int x, int y) { return x + 3 * y; }
} barObj;

int main(int argc, char const *argv[])
{
    int init = 100;
    std::vector<int> vect = {10, 20, 30};
    std::cout << std::accumulate(vect.begin(), vect.end(), init) << "\n";
    std::cout << std::accumulate(vect.begin(), vect.end(), init, std::minus<int>()) << "\n";
    std::cout << std::accumulate(vect.begin(), vect.end(), init, foo) << "\n";
    std::cout << std::accumulate(vect.begin(), vect.end(), init, barObj) << "\n";
    
    return 0;
}

