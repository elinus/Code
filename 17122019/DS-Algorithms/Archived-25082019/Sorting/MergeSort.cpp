#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

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

void merge(vector<int> &arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergesort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    int n = 0;
    cout << "enter number = ";
    cin >> n;
    vector<int> vec(n);
    getRandomNumbers(vec);
    print(vec);
    mergesort(vec, 0, vec.size() - 1);
    print(vec);
    return 0;
}

