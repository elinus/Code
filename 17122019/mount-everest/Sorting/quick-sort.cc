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

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

int rand_partition(int arr[], int l, int r) {
    int random = l + rand() % (r - l + 1);
    std::swap(arr[random], arr[l]);
    return partition(arr, l ,r);
}

void quick_sort(int arr[], int l, int r) {
    if (l < r) {
        int pivot = rand_partition(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> nums = generateRandomNumbers(20, 10, 99);
    int *arr = nums.data();
    print(arr, 20);
    quick_sort(arr, 0, nums.size() - 1);
    print(arr, 20);

    return 0;
}

