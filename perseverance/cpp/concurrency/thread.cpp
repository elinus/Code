#include <iostream>
#include <memory>
#include <thread>

void f1(int n) {}
void f2(int &n) {}

int main(int argc, char const *argv[])
{
    int n = 0;
    std::thread t1;
    std::thread t2(f1, n+1);
    std::thread t3(f2, std::ref(n));
    std::thread t4(std::move(t3));
    if (t2.joinable()) t2.join();
    t4.join();

    std::cout << "Hardware concurrency = " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "thr id :: " << std::this_thread::get_id() << std::endl;
    return 0;
}
