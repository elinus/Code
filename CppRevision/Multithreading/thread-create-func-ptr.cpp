#include <iostream>
#include <thread>

void foo() {
    for (int i = 0; i < 1000; i++) {
        std::cout << "thread function executing.. [ id = " << std::this_thread::get_id() << " ]" << std::endl;
    }
}

int main (int argc, char *argv[])
{
    std::thread t1(foo);
    for (int i = 0; i < 1000; i++) {
        std::cout << "main function executing.. { id = " << t1.get_id() << " }"<< std::endl;
    }

    t1.join();
    std::cout << "Exiting main function!" << std::endl;
    return 0;
}

