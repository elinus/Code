#include <iostream>
#include <vector>
#include <string>
#include <list>

template<typename T>
void print(const std::vector<T> & vec, const std::string & tag = "") {
    std::cout << tag << " :: ";
    for (auto i = 0; i < vec.size(); ++i) {
        std::cout << "(" << i << ")"<< vec[i] << " ";
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {
    
    // 1
    std::vector<int> v1(5);
    print(v1, "v1");

    std::vector<std::string> v2(5, "Hello");
    print(v2, "v2");

    std::string arr[] = {"one", "two", "three", "four", "five"};
    std::vector<std::string> v3(arr, arr + sizeof(arr)/sizeof(arr[0]));
    print(v3, "v3");

    std::list<std::string> l1;
    l1.push_back("one");
    l1.push_back("two");
    l1.push_back("three");
    l1.push_back("four");
    l1.push_back("five");
    std::vector<std::string> v4(l1.begin(), l1.end());
    print(v4, "v4");

    std::vector<int> v5(v1);
    print(v5, "v5");
    return 0;
}

