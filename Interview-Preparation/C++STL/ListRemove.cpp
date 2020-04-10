#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main (int argc, char *argv[]) {
    list<int> l1({1, 2, 3, 4, 5});
    for (int i = 1; i <= 10; ++i) {
        l1.push_back(i);
        l1.push_front(i - 1);

        if (i % 2) l1.push_back(0);
    }

    copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    l1.remove(0);

    copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    l1.remove_if([](const int & value) {
            if (value >= 2 && value <= 4) 
            return true;
            else 
            return false;
            });
    
    copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    
    return 0;
}

