#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <vector>
#include <functional>
#include <algorithm>

template<typename T, typename U>
void erase_if(T & container, U first, U last, std::function<bool (U)> checker) {
    while (first != last) {
        if (checker(first)) {
            first = container.erase(first);
        } else {
            first++;
        }
    }
}

int main (int argc, char *argv[]) {
    std::set<std::string> s_ = {"hi", "hello", "is", "the", "at", "hi", "is", "from", "that"};
    std::copy(s_.begin(), s_.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\n";

    typedef std::set<std::string>::iterator sIter;
    std::function<bool (sIter)> lambda = [](sIter it) -> bool {
        return it->size() > 2;
    };
    
    erase_if(s_, s_.begin(), s_.end(), lambda);
    
    std::copy(s_.begin(), s_.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << "\n";
    
    return 0;
}

