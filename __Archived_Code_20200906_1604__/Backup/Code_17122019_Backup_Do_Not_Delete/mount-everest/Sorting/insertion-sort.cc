#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

std::vector<int> generateRandomNumbers(int n, int min_num, int max_num) {
    std::vector<int> nums(n);
    for (int i = 0; i< n; i++) {
        nums[i] = min_num + rand() % (max_num - min_num + 1); 
    }
    return nums;
}

void print(const std::vector<int> &nums) {
    for (const int &x: nums) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void insertion_sort(std::vector<int> &nums) {
    size_t n = nums.size();
    for (int i = 0; i < n; i++) {
        int key = nums[i];
        int j = i;
        while (j > 0 && nums[j-1] > key) {
            nums[j] = nums[j-1];
            j--;
        }
        nums[j] = key;
    }
}

int main (int argc, char *argv[]) {
    
    srand(time(nullptr));    
    std::vector<int> nums = generateRandomNumbers(50, 100, 999);
    print(nums);

    insertion_sort(nums);
    print(nums);

    return 0;
}

