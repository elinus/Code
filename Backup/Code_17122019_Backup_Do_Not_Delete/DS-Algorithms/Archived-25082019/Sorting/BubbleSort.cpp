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

void bubblesort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    vector<int> vec(20);
    getRandomNumbers(vec);
    print(vec);
    bubblesort(vec);
    print(vec);
    return 0;
}

