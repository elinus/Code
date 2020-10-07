#include <iostream>
#include <string>
#include <vector>
#include <chrono>

static uint32_t s_allocCount = 0;

void* operator new(size_t size) {
    s_allocCount++;
    std::cout << __func__ << ": Allocating.. " << size << " bytes!\n";
    return malloc(size);
}

void PrintName(const std::string &name) {
    std::cout << __func__ << ": " << name << std::endl;
}

void print(const std::vector<std::string> &vec) {
    std::cout << "---------- START ----------\n";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "---------- END ----------\n";
}

int main(int argc, char const *argv[]) {
    std::string name = "Sunil Mourya";
    PrintName(name);
    std::cout << "Allocated = " << s_allocCount << "\n";
    std::vector<std::string> nums_vec;
    for (int i = 0; i < 25; ++i) {
        nums_vec.push_back(std::to_string(double(i) * i * 22 / 7));
    }
    
    auto start1 = std::chrono::steady_clock::now();
    print(nums_vec);
    auto end1 = std::chrono::steady_clock::now();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();
    std::cout << "elapsed 1 = " << elapsed1 << "\n";
    
    return 0;
}

