#include <iostream>
#include <vector>
#include <map>
#include <string>

struct AllocationMetrics {
    uint32_t totalAllocated = 0;
    uint32_t totalFreed = 0;
    uint32_t CurrentUsage() {
        return totalAllocated - totalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
    void* memory_addr = malloc(size);
    s_AllocationMetrics.totalAllocated += size;
    std::cout << "Allocating : " << size << " bytes  @ addr :: " << memory_addr << "\n";
    return memory_addr;
}

void operator delete(void *memory, size_t size) {
    s_AllocationMetrics.totalFreed += size;
    std::cout << "Deleteing memory :: " << memory << "\n";
    free(memory);
}

void Foo(const std::vector<int> &vec) {
    std::cout << "Foo - return\n";
}

int main (int argc, const char *argv[]) {
    int *ip = new int(14);
    delete ip;
    //std::cout << " ====== " << s_AllocationMetrics.CurrentUsage() << "\n";
    std::vector<int> vec(10);
    for(int i = 0; i < 10; i++) {
        //vec.push_back(i);
        vec[i] = i;
    }

    //std::cout << " ====== " << s_AllocationMetrics.CurrentUsage() << "\n";
    std::cout << "Calling foo\n";
    Foo(vec);

    //std::cout << " ====== " << s_AllocationMetrics.CurrentUsage() << "\n";
    std::cout << "Map ::\n";
    std::map<int, int> m;
    m[0] = 0;
    m[1] = 1;
    
    //std::cout << " ====== " << s_AllocationMetrics.CurrentUsage() << "\n";

    std::cout << "vector(vector(string)) ::\n";
    std::vector<std::vector<std::string>> vvs;
    vvs.push_back({});
    vvs[0].push_back("1");

    //std::cout << " ====== " << s_AllocationMetrics.CurrentUsage() << "\n";
    return 0;
}

