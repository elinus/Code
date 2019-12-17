#include <iostream>
#include <string>
#include <vector>
#include <list>

int main (int argc, char const *argv[])
{
    std::vector<int> v1(10);
    for (int x: v1) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    std::vector<std::string> v2(10, "Hi!");
    for (std::string x: v2) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::string arr[] = {"first", "second", "third", "forth", "five"};
    std::vector<std::string> v3(arr, arr + sizeof(arr) / sizeof(std::string));
    for (std::string x: v3) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::vector<std::string> v4(v3);
    for (std::string x: v4) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";
   
    std::list<std::string> list1;
    for (int i = 0; i < 5; i++) {
        list1.push_back(arr[i]);
    }
    std::vector<std::string> v5(list1.begin(), list1.end());
    for (std::string x: v5) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}

