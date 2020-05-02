#include <iostream>
#include <thread>
#include <future>

void foo(std::promise<int> *promiseObj) {
    std::cout << "Inside thread!" << std::endl;
    promiseObj->set_value(20);
}

int main(int argc, char const *argv[])
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(foo, &promiseObj);
    std::cout << futureObj.get() << std::endl;
    th.join();
    return 0;
}

