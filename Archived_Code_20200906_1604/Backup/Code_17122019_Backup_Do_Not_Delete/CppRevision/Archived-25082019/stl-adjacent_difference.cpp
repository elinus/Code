#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char const *argv[])
{
    int init = 100;
    std::vector<int> vec_a{1, 2, 3, 4, 5, 10, 9, 8, 6, 7};
    std::vector<int> vec_b(vec_a.size());
    std::adjacent_difference(vec_a.begin(), vec_a.end(), vec_b.begin());
    for (auto x: vec_b) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}

