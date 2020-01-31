#include <iostream>
#include <vector>
#include <algorithm>

struct RandomGenerator {
    int maxValue;
    RandomGenerator(int maxValue) {
        this->maxValue = maxValue;
    }
    int operator ()() {
        return rand() % maxValue;
    }
};

int main (int argc, char *argv[]) {
    std::vector<int> vec1(10);
    std::cout << "Generate random number using lambda expression\n";
    std::generate(vec1.begin(), vec1.end(), [](){
            return rand() % 100;
            });
    for (const int &x: vec1) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::vector<int> vec2(10);
    std::cout << "Generate random number using Functor\n";
    std::generate(vec2.begin(), vec2.end(), RandomGenerator(1000));
    for (const int &x: vec2) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    
    return 0;
}

