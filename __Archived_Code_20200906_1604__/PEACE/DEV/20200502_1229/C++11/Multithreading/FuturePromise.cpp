#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void initiazer(std::promise<int> * promObj) {
    std::cout << "Inside Thread" << std::endl;     
    promObj->set_value(35);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Sleep done!" << std::endl;
}

int main() {
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(initiazer, &promiseObj);
    std::cout << "Waiting for future set.." << std::endl;
    std::cout<< futureObj.get() <<std::endl;
    std::cout << "Future get received." << std::endl;
    th.join();
    std::cout << "Done!" << std::endl;
    return 0;
}
