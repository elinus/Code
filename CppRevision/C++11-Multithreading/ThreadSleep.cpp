#include <iostream>
#include <chrono>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << std::this_thread::get_id() << " :: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(foo);
    if (t1.joinable()) {
        t1.join();
    }

    std::cout << "CHECKPOINT #1, tid = " << std::this_thread::get_id() << std::endl;
    return 0;
}

