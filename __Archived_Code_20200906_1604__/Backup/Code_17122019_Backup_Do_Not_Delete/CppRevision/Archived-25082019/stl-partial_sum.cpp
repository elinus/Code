#include <iostream>
#include <numeric>
#include <vector>

int foo(int x, int y) {
    return x + 2 * y;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec_a{10, 20, 30, 40, 50};
    std::vector<int> vec_b(vec_a.size());
    std::partial_sum(vec_a.begin(), vec_a.end(), vec_b.begin());
    for (auto x: vec_b) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::partial_sum(vec_a.begin(), vec_a.end(), vec_b.begin(), foo);
    for (auto x: vec_b) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}

