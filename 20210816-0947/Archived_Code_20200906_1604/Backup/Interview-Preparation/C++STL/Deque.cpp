#include <iostream>
#include <deque>

int main (int argc, char *argv[]) {
    
    std::deque<int> deqObj;
    
    deqObj.push_front(4);
    deqObj.push_front(3);
    deqObj.push_back(5);
    deqObj.push_back(6);

    for (auto it = deqObj.begin(); it != deqObj.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "deque size = " << deqObj.size() << "\n";
    std::cout << "deque max-size = " << deqObj.max_size() << "\n";
    std::cout << "deqObj[2] = " << deqObj[2] << "\n";
    std::cout << "deqObj.at(3) = " << deqObj.at(3) << "\n";
    std::cout << "deqObj.front() = " << deqObj.front() << "\n";
    std::cout << "deqObj.back() = " << deqObj.back() << "\n";

    deqObj.pop_front();
    
    for (auto it = deqObj.begin(); it != deqObj.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    deqObj.pop_back();
    
    for (auto it = deqObj.begin(); it != deqObj.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}

