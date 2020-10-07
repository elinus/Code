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

void SelectionSort(std::vector<int> & vec) {
    size_t n = vec.size();
    for (auto i = 0; i < n-1; i++) {
        int minimum = vec[i];
        for (auto j = i+1; j < n; j++) {
            if (vec[j] < vec[minimum]) {
                minimum = j;
            }
        }
        std::swap(vec[i], vec[minimum]);
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> vec(NUM_INTS);
    std::generate(vec.begin(), vec.end(), random_num);
    print(vec);
    auto start = std::chrono::system_clock::now();
    SelectionSort(vec);
    auto end = std::chrono::system_clock::now();
    print(vec);
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "~ " << dur.count() << " ms.\n";
    return 0;
}

