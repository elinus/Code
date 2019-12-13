#include <iostream>
#include <ctime>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void bubble_sort(int arr[], int n) {
    int temp;
    bool sorted = false;
    for (int k = 0; k < n-1; k++) {
        sorted = true;
        for (int i =0; i < n-k-1; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    const int min = 100;
    const int max = 999;
    const int size = 50;
    int arr[size] = {0};

    for (int i = 0; i < 50; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }

    std::cout << "Without sorting:\n";
    print(arr, size);

    bubble_sort(arr, size);
    
    std::cout << "After sorting:\n";
    print(arr, size);

    return 0;
}

