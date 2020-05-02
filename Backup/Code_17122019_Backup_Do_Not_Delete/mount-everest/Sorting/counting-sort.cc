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

void counting_sort(std::vector<int> &nums) {
    size_t n = nums.size();
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = k > nums[i] ? k : nums[i];
    }

    std::vector<int> aux(k+1, 0);

    for (int i = 0; i < n; i++) {
        aux[nums[i]]++;
    }

    int j = 0;
    for (int i = 0; i <= k; i++) {
        int count = aux[i];
        while (count--) {
            nums[j++] = i;
        }
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> nums = generateRandomNumbers(50, 0, 9);
    print(nums);

    counting_sort(nums);
    print(nums);

    return 0;
}

