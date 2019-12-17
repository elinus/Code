#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threadList;
    std::function<void()> func = []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout << __func__ << " :: " << std::this_thread::get_id() << std::endl;
    };

    threadList.push_back(std::thread(func));
    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);
    
    threadList.push_back(std::move(t1));
    threadList.push_back(std::move(t2));
    threadList.push_back(std::move(t3));

    std::thread t4(func);
    if (threadList[1].joinable()) {
        threadList[1].join();
    }

    threadList[1] = std::move(t4);

    std::vector<std::thread> newThreadList = std::move(threadList);
    for (std::thread & t : newThreadList) {
        if (t.joinable()) {
            t.join();
        }
    }
    return 0;
}

