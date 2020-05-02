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

void selection_sort(std::vector<int> &nums) {
    size_t n = nums.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            std::swap(nums[i], nums[min_index]);
        }
    }
}

void print(const std::vector<int> &nums) {
    for (const int &x: nums) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));    
    
    std::vector<int> nums = generateRandomNumbers(50, 100, 999);
    print(nums);

    selection_sort(nums);
    print(nums);

    return 0;
}

