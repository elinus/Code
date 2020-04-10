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
    }

    copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    auto it = l1.begin();
    ++it;
    l1.erase(it);

    copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    return 0;
}

