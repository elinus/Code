#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void foo(std::promise<int> *promiseObj) {
    std::cout << "Inside foo func." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    promiseObj->set_value(14);
}

int main (int argc, char const *argv[])
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread t1(foo, &promiseObj);
    std::cout << "waiting for future object..!" << std::endl;
    std::cout << "futureObj = " << futureObj.get() << std::endl;
    std::cout << "done!" << std::endl;
    t1.join();
    return 0;
}

