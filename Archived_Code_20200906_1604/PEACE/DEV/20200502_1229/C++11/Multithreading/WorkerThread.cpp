#include <iostream>
#include <thread>
#include <functional>
#include <vector>
#include <algorithm>

struct WorkerThread {
    void operator()() {
        std::cout << "Worker thread :: " << std::this_thread::get_id() << " is executing!\n";
    }
};

int main (int argc, char *argv[]) {
    std::vector<std::thread> wt_vecs_;
    for (size_t i = 0; i < 10; i++) {
        wt_vecs_.push_back(std::thread { WorkerThread() });
    }
    std::cout << "Waiting for all threads to join\n";
    std::for_each(wt_vecs_.begin(), wt_vecs_.end(), std::mem_fn(&std::thread::join));
    std::cout << "All threads joined!!\n";
    return 0;
}

