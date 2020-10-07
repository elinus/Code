#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <functional>
#include <algorithm>

void coco(int i) {
    static std::mutex m_;
    std::lock_guard<std::mutex> lck(m_);
    std::cout << "tid=" << std::this_thread::get_id() << ", i = " << i << "\n";
}

int main (int argc, const char *argv[]) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 20; ++i) {
        threads.push_back(std::thread(coco, i));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    return 0;
}

