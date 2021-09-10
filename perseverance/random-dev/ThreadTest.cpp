#include <iostream>
#include <thread>
#include <chrono>

void foo() {
    std::cout << "Inside thread = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Exiting foo!" << std::endl;
}

int main(int argc, char const *argv[]) {
    std::thread t1(foo);
    t1.join();
    std::cout << "Exiting main thread = " << std::this_thread::get_id() << std::endl;
    return 0;
}
