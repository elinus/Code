#include <iostream>
#include <chrono>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << std::this_thread::get_id() << " :: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void bar_time_point(std::chrono::system_clock::time_point tp) {
    std::time_t ts = std::chrono::system_clock::to_time_t(tp);
    std::cout << std::ctime(&ts) << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(foo);
    if (t1.joinable()) {
        t1.join();
    }

    std::cout << "CHECKPOINT #1, tid = " << std::this_thread::get_id() << std::endl;

    std::cout << "Current time :: ";
    bar_time_point(std::chrono::system_clock::now());
    std::chrono::system_clock::time_point tp = 
        std::chrono::system_clock::now() + std::chrono::seconds(20);
    
    std::cout << "Going to sleep until :: ";
    bar_time_point(tp);
    std::this_thread::sleep_until(tp);
    
    std::cout << "Current time :: ";
    bar_time_point(std::chrono::system_clock::now());
    
    return 0;
}

