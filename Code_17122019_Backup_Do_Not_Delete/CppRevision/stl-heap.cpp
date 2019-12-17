#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[]) {
    
    std::vector<int> v1 = {14, 20, 24, 11, 16};
    std::make_heap(v1.begin(), v1.end()); // convert to heap
    std::cout << "front = " << v1.front() << "\n"; // first elem
    for(int &x: v1) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    v1.push_back(25);
    std::push_heap(v1.begin(), v1.end());
    std::cout << "front = " << v1.front() << "\n"; // first elem
    
    std::pop_heap(v1.begin(), v1.end());
    v1.pop_back();
    std::cout << "front = " << v1.front() << "\n"; // first elem
    
    sort_heap(v1.begin(), v1.end());
    for (int &x: v1) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    std::cout << std::is_heap(v1.begin(), v1.end()) << "\n";
    return 0;
}

