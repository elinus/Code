#include <iostream>
#include <chrono>
#include <future>
#include <thread>

constexpr auto tenMill = 10000000;

class MySingleton {
    public:
        static MySingleton& getInstance() {
            static MySingleton instance;
            return instance;
        }
    private:
        MySingleton() = default;
        ~MySingleton() = default;
        MySingleton(const MySingleton &other) = delete;
        MySingleton& operator=(const MySingleton &other) = delete; 

};

std::chrono::duration<double> getTime() {
    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; ++i) {
        MySingleton::getInstance();
    }
    auto end = std::chrono::system_clock::now();
    return end - begin;
}

int main (int argc, char const *argv[])
{
    auto future1 = std::async(std::launch::async, getTime);
    auto future2 = std::async(std::launch::async, getTime);
    auto future3 = std::async(std::launch::async, getTime);
    auto future4 = std::async(std::launch::async, getTime);
    auto total = future1.get() + future2.get()  + future3.get() + future4.get();
    std::cout << total.count() << std::endl;
    return 0;
}

