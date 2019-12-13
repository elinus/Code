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

void merge(int arr[], int start, int mid, int end) {
    int p = start, q = mid + 1;
    int temp[end - start + 1], k = 0;
    for (int i = start; i <= end; i++) {
        if (p > mid) {
            temp[k++] = arr[q++];
        } else if (q > end) {
            temp[k++] = arr[p++];
        } else if (arr[p] < arr[q]) {
            temp[k++] = arr[p++];
        } else {
            temp[k++] = arr[q++];
        }
    }

    for (int p = 0; p < k; p++) {
        arr[start++] = temp[p];
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> nums = generateRandomNumbers(20, 10, 99);
    int *arr = nums.data();
    print(arr, 20);
    merge_sort(arr, 0, nums.size() - 1);
    print(arr, 20);

    return 0;
}

