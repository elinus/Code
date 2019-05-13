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

void countingsort(vector<int> &arr) {
    size_t size = arr.size();
    vector<int> count(size, 0);
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    print(count);
    for (int i = 1; i < size; i++) {
        count[i] += count[i-1];
    }
    print(count);
    vector<int> output(size);
    for (int i = size; i >= 1; i--) {
        output[count[arr[i]]] = arr[i];
        count[arr[i]]--;
    };
    print(output);
}

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    vector<int> vec(10);
    getRandomNumbers(vec);
    print(vec);
    countingsort(vec);
    return 0;
}

