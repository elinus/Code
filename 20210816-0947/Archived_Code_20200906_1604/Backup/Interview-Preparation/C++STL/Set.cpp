#include <iostream>
#include <set>
#include <iterator>
#include <string>

int main (int argc, char *argv[]) {
    std::set<std::string> s1;
    s1.insert("one");
    s1.insert("two");
    s1.insert("three");
    s1.insert("four");
    s1.insert("five");
    s1.insert("six");
    std::cout << (s1.insert("seven").second ? "element inserted successfully\n" : "element already present\n");
    std::cout << (s1.insert("seven").second ? "element inserted successfully\n" : "element already present\n");


    std::cout << s1.size() << "\n";
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Find
    auto it1 = s1.find("one");
    if (it1 != s1.end()) std::cout << "Element present.\n";
    auto it2 = s1.find("ten");
    if (it2 == s1.end()) std::cout << "Element not present.\n";

    // Erase
    s1.erase("three");
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}

