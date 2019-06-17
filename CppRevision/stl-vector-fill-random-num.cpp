#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, char const *argv[])
{
    std::vector<int> vec(100);
    std::generate(vec.begin(), vec.end(), []() {
            return rand() % 100;
            });

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}

