#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
    
    std::vector<int> v;
    for(auto i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    for (auto i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

