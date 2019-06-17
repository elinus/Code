#include <iostream>
#include <vector>
#include <algorithm>

struct RandomGen {
    int maxValue;
    RandomGen(int max) {
        maxValue = max;
    }
    int operator ()() {
        return rand() % maxValue;
    }
};

int main (int argc, char const *argv[])
{
    std::vector<int> vec(100);
    std::generate(vec.begin(), vec.end(), []() {
            return rand() % 100;
            });

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    
    // using functor
    std::generate(vec.begin(), vec.end(), RandomGen(500));
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}

