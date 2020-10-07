#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

int main (int argc, char *argv[]) {
    std::string name = "sunilmourya";
    std::vector<char> permutations(name.begin(), name.end());
    //for (int i = 0; i < 3; ++i) {
    //    permutations.push_back(i);
    //}

    do {
        //std::copy(permutations.begin(), permutations.end(), std::ostream_iterator<char>(std::cout, ""));
        std::string str(permutations.begin(), permutations.end());
        if (str.find("sunil") != std::string::npos)
            std::cout << str << "\n";
        //std::cout << "\n";
    } while (std::next_permutation(permutations.begin(), permutations.end()));


    return 0;
}

