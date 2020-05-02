#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void foo(std::future<void> futureObj) {
    std::cout << "Thread Start" << std::endl;
    while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout) {
        std::cout << "Doing Some Work" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "Thread End!" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::promise<void> promiseObj;
    std::future<void> futureObj = promiseObj.get_future();
    std::thread th(foo, std::move(futureObj));
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Asking thread to stop!" << std::endl;
    promiseObj.set_value();
    th.join();
    std::cout << "Exiting Main Function!" << std::endl;
    return 0;
}

