#include <iostream>
#include <chrono>
#include <future>
#include <thread>
#include <mutex>
#include <atomic>

constexpr auto tenMill = 10000000;

class MySingleton {
    public:
        static MySingleton* getInstance() {
            MySingleton *sin = instance.load(std::memory_order_acquire);
            if (!sin) {
                std::lock_guard<std::mutex> mLock(myMutex);
                sin = instance.load(std::memory_order_relaxed);
                if (!sin) {
                    sin = new MySingleton();
                    instance.store(sin, std::memory_order_release);
                }
            }
            return sin;
        }
    private:
        MySingleton() = default;
        ~MySingleton() = default;
        MySingleton(const MySingleton &other) = delete;
        MySingleton& operator=(const MySingleton &other) = delete; 
        static std::atomic<MySingleton*> instance;
        static std::mutex myMutex;
};

std::atomic<MySingleton*> MySingleton::instance;
std::mutex MySingleton::myMutex;

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

