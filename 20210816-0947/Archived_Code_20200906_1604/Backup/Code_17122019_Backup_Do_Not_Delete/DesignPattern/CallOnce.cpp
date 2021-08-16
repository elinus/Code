#include <iostream>
#include <thread>
#include <mutex>

std::once_flag gOnceFlag;

void do_once() {
    std::call_once(gOnceFlag, [](){ std::cout << "Only once!" << std::endl; });
}

int main (int argc, char const *argv[])
{
    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);
    std::thread t4(do_once);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}

