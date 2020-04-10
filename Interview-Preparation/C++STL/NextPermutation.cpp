#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main (int argc, char *argv[]) {
    std::vector<int> permutations;
    for (int i = 0; i < 3; ++i) {
        permutations.push_back(i);
    }

    do {
        std::copy(permutations.begin(), permutations.end(), std::ostream_iterator<int>(std::cout, ""));
        std::cout << "\n";
    } while (std::next_permutation(permutations.begin(), permutations.end()));


    return 0;
}

