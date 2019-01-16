#include <iostream>
#include <unordered_set>
#include <string>

int main (int argc, char *argv[])
{
    std::unordered_set<std::string> uset;
    uset.insert("First");
    uset.insert("Second");
    uset.insert("third");

    for (std::string elem : uset) {
        std::cout << elem << std::endl;
    }
    return 0;
}

