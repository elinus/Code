#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

const int NUM_INTS = 10;

int main (int argc, char *argv[]) {
    std::vector<int> vec(NUM_INTS);
    std::generate(vec.begin(), vec.end(), rand);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    return 0;
}

