#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void initiazer(std::promise<int> * promObj)
{
    std::cout<< "Inside Thread" << std::endl;     
    promObj->set_value(35);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "exit thread: " << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    
    std::cout << "Starting thread.." << std::endl;
    std::thread th(initiazer, &promiseObj);

    std::cout << futureObj.get() << std::endl;

    th.join();
    std::cout << "exit main" << std::endl;
    return 0;
}
