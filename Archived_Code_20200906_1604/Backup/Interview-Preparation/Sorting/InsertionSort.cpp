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

void InsertionSort(std::vector<int> & vec) {
    size_t n = vec.size();
    for (auto i = 1; i < n; i++) {
        int temp = vec[i];
        int j = i;
        while (j > 0 && vec[j-1] > temp) {
            vec[j] = vec[j-1];
            j = j-1;
        }
        vec[j] = temp;
    }
}

int main (int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<int> vec(NUM_INTS);
    std::generate(vec.begin(), vec.end(), random_num);
    print(vec);
    auto start = std::chrono::system_clock::now();
    InsertionSort(vec);
    auto end = std::chrono::system_clock::now();
    print(vec);
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "~ " << dur.count() << " ms.\n";
    return 0;
}

