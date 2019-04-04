#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>

std::string foo(std::string param) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return param;
}

std::string bar(std::string param) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return param;
}

int main (int argc, char const *argv[])
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::future<std::string> futureObj = std::async(std::launch::async, foo, "Hello"); // deferred
    std::string bar_data = bar("World!");
    std::string foo_data = futureObj.get();
    auto end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast <std::chrono::milliseconds>(end - start).count();
    std::cout << "time taken = " << diff << " msec." << std::endl;
    std::cout << "foo_data + bar_data = { " << foo_data + bar_data << " }" << std::endl;
    return 0;
}

