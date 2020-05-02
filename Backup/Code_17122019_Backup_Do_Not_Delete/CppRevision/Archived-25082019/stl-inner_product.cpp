#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char const *argv[])
{
    int init = 100;
    std::vector<int> vec_a{1, 2, 3, 4, 5};
    std::vector<int> vec_b{10, 20, 30, 40, 50};
    std::cout << std::inner_product(vec_a.begin(), vec_a.end(), vec_b.begin(), init) << "\n";
    return 0;
}

