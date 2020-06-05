#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

void coco() {
    std::cout << "tid=" << std::this_thread::get_id() << ", sleeping for 5 secs..\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "tid=" << std::this_thread::get_id() << ", done sleeping..\n";
}

int main (int argc, const char *argv[]) {
    std::thread t1(coco);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t2 = std::move(t1);
    t2.join();
    std::cout << "All threads joined. Exiting main=" << std::this_thread::get_id() << "\n";
    return 0;
}

