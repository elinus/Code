#include <iostream>
#include <chrono>

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

int main (int argc, char const *argv[])
{
    constexpr auto fortyMill =  4 * tenMill;
    std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
    //auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i < fortyMill; ++i) {
        MySingleton::getInstance();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time_diff = std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
    std::cout << time_diff.count() << std::endl;
    //std::cout << std::chrono::duration<double>(end - begin).count() << std::endl;
    return 0;
}

