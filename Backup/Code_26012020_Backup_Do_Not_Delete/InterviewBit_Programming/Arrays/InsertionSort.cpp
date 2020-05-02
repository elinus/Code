#include <iostream>
#include <vector>

void Print(const std::vector<int>& vec) {
    for(int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void InsertionSort(std::vector<int>& vec) {
    for(int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main (int argc, char *argv[]) {
    std::vector<int> vec { 25, 17, 31, 13, 2 };
    
    Print(vec);
    InsertionSort(vec);
    Print(vec);

    return 0;
}

