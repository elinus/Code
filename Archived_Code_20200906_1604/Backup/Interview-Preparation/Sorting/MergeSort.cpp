#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <cstdlib>
#include <ctime>

const int NUM_INTS = 100000;

void print(const std::vector<int> & vec) {
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

int random_num() {
    return rand() % NUM_INTS;
}

void Merge(std::vector<int> &vec, int start, int mid, int end) {
    int p = start, q = mid+1, k = 0;
    int A[end-start+1];
    for (int i = start; i <= end; i++) {
        if (p > mid) {
            A[k++] = vec[q++];
        } else if (q > end) {
            A[k++] = vec[p++];
        } else if (vec[p] < vec[q]) {
            A[k++] = vec[p++];
        } else {
            A[k++] = vec[q++];
        }
    }
    for (int i = 0; i < k; i++) {
        vec[start++] = A[i];
    }
}

void MergeSort(std::vector<int> & vec, int start, int end) {
    if (start < end) {
        int mid = (start+end)/2;
        MergeSort(vec, start, mid);
        MergeSort(vec, mid+1, end);
        Merge(vec, start, mid, end);
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> vec(NUM_INTS);
    std::generate(vec.begin(), vec.end(), random_num);
    print(vec);
    auto start = std::chrono::system_clock::now();
    MergeSort(vec, 0, vec.size()-1);
    auto end = std::chrono::system_clock::now();
    print(vec);
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "~ " << dur.count() << " ms.\n";
    return 0;
}

