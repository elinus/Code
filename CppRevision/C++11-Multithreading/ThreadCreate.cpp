#include <iostream>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << i << std::endl;
    }
}

void bar() {
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << i << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    /* Thread creation using function pointer */
    std::thread t1(foo);
    bar();
    t1.join();

    /* Thread creation using lambda function */
    std::thread t2([]{
            for (int i = 0; i < 5; i++) {
                std::cout << "Lambda func: " << __func__ << ":=> " << i << std::endl;
            }
            });
    bar();
    t2.join();

    std::cout << "Exiting main thread!" << std::endl;
    return 0;
}

