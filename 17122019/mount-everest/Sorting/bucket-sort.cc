#include <iostream>
#include <vector>
#include <algorithm>

void print(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void bucket_sort(double arr[], int n) {
    
    std::vector<double> buckets[n];
    
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        buckets[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }

}

int main (int argc, char *argv[]) {
    
    double arr[] = {0.1409, 0.2003, 0.2410, 0.2512, 0.1103, 0.1611 };
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr, n);
    bucket_sort(arr, n);
    print(arr, n);
    return 0;
}

