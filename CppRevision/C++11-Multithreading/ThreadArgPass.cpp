#include <iostream>
#include <thread>
#include <string>

void foo(int x, std::string str) {
    std::cout << "tid = " << std::this_thread::get_id() 
        << ", int = " << x 
        << ", string = " << str << std::endl; 
}

int main(int argc, char const *argv[])
{
    std::thread t1(foo, 14, "elinus!");
    if (t1.joinable()) {
        t1.join();
    }
    std::cout << "exiting tid = " << std::this_thread::get_id() << std::endl;
    return 0;
}

