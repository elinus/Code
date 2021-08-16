#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void foo(std::promise<int> *promiseObj) {
    std::cout << "Inside thread " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    promiseObj->set_value(14);
}

int main (int argc, char *argv[]) 
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(foo, &promiseObj);
    std::cout << "Waiting for future..\n";
    std::cout << futureObj.get() << std::endl;
    th.join();
    return 0;
}

