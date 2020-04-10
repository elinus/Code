#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

int main (int argc, char *argv[]) {
    std::list<std::string> l1 = {"one", "two", "three", "four", "five"};
    std::copy(l1.begin(), l1.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\n";

    auto it1 = l1.begin();
    std::advance(it1, 2);
    std::cout << *it1 << "\n";
    
    auto it2 = next(l1.begin(), 2);
    std::cout << *it2 << "\n";
    
    return 0;
}

