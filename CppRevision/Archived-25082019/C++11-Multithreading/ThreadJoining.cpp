#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

class WorkerThread {
    public:
        void operator ()() {
            std::cout << "Worker thread = " << std::this_thread::get_id() 
                << " is executing!" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threadVec;
    for (int i = 0; i < 10; i++) {
        threadVec.push_back(std::thread(WorkerThread()));
    }

    for_each(threadVec.begin(), threadVec.end(), std::mem_fn(&std::thread::join));
    std::cout << "CHECKPOINT#1, tid = " << std::this_thread::get_id() << std::endl;
    
    std::thread t1{WorkerThread()};
    if (t1.joinable()) {
        t1.join();
    }
    
    std::cout << "CHECKPOINT#2, tid = " << std::this_thread::get_id() << std::endl;
    std::thread t2{WorkerThread()};
    if (t2.joinable()) {
        t2.detach();
    }
    
    std::cout << "Exiting main thread! id = " << std::this_thread::get_id() << std::endl;
    return 0;
}

