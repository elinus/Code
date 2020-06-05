#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

void zaki() {
    std::cout << "tid=" << std::this_thread::get_id() << ", sleeping for 3 secs..\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "tid=" << std::this_thread::get_id() << ", done sleeping..\n";
}

void coco() {
    std::cout << "tid=" << std::this_thread::get_id() << ", sleeping for 5 secs..\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "tid=" << std::this_thread::get_id() << ", done sleeping..\n";
}

int main (int argc, const char *argv[]) {
    std::thread t1(coco);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t2 = std::move(t1);
    t1 = std::thread(zaki); 
    std::thread t3 = std::move(t2);
    t1.join();
    t3.join();
    std::cout << "All threads joined. Exiting main=" << std::this_thread::get_id() << "\n";
    return 0;
}

