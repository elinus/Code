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

void insertionsort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    vector<int> vec(20);
    getRandomNumbers(vec);
    print(vec);
    insertionsort(vec);
    print(vec);
    return 0;
}

