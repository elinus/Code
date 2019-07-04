#include <iostream>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << i << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    /* Thread creation using function pointer */
    std::thread t1(foo);
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << i << std::endl;
    }
    t1.join();
    std::cout << "Exiting main thread!" << std::endl;
    return 0;
}

