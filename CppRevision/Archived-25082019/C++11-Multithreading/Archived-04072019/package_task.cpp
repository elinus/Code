#include <iostream>
#include <thread>
#include <future>
#include <string>

std::string foo( std::string param)
{
    std::string data = "passed param = " + param;
    return data;
}

int main (int argc, char const *argv[])
{
    std::packaged_task<std::string (std::string)> task(foo);
    std::future<std::string> result = task.get_future();
    std::thread th(std::move(task), "HelloWorld!");
    th.join();
    std::string data = result.get();
    std::cout << data << std::endl;
    
    return 0;
}

