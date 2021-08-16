#include <iostream>
#include <ctime>
#include <vector>

std::vector<int> generateNumbers(int n, int min, int max) {
    std::vector<int> rand_nums(n);
    for (int i = 0; i < n; i++) {
        rand_nums[i] = rand() % (max - min + 1) + min;
    }
    return rand_nums;
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    int minimum = 100;
    for (int i = 0; i < 10; i++) {
        std::cout << minimum + rand() % 100 + 1 << "\n";
    }

    std::vector<int> nums = generateNumbers(25, 1000, 9999);
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    return 0;
}

