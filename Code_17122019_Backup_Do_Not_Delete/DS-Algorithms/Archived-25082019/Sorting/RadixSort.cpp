#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void getRandomNumbers(vector<int> &numsVec) {
    size_t size = numsVec.size();
    for (int i = 0; i < size; i++) {
        numsVec[i] = rand() % size;
    }
}

void print(const vector<int> &numsVec) {
    for (auto it = numsVec.begin(); it != numsVec.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

void countingsort(vector<int> &arr, int mul) {
    size_t size = arr.size();
    vector<int> freq(10, 0);
    for (int i = 0; i < size; i++) {
        freq[(arr[i] / mul) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i-1];
    }
    vector<int> output(size);
    for (int i = size - 1; i >= 0; i--) {
        output[freq[(arr[i] / mul) % 10] - 1] = arr[i];
        freq[(arr[i] / mul) % 10]--;
    };
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

}

void radixsort(vector<int>& arr) {
    int max_elem = *max_element(arr.begin(), arr.end());
    int mul = 1;
    while (max_elem) {
        countingsort(arr, mul);
        mul *= 10;
        max_elem /= 10;
    }
}

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    vector<int> vec(200);
    getRandomNumbers(vec);
    print(vec);
    radixsort(vec);
    print(vec);
    return 0;
}

