#include <iostream>
#include <thread>
#include <string>

void foo(int i, std::string str)
{
    std::cout << "int i = " << i << std::endl;
    std::cout << "string str = " << str << std::endl;
}

int main (int argc, char *argv[])
{
    int i = 14;
    std::string str = "elinus";
    std::thread t1(foo, i, str);

    t1.join();
    std::cout << "main: " << std::this_thread::get_id() << std::endl;
    return 0;
}

