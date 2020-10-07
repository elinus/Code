#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello Concurrent World!\n";
}

int main (int argc, char *argv[]) {
    std::thread t1(hello);
    t1.join();
    return 0;
}

