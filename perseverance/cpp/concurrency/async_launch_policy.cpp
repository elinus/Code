#include <iostream>
#include <future>
#include <chrono>

void print_ten(char c, int ms) {
    for (size_t i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::cout << c;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "with launch::aysnc .." << std::endl;
    std::future<void> foo = std::async(std::launch::async, print_ten, 'S', 100);
    std::future<void> bar = std::async(std::launch::async, print_ten, 'A', 200);
    foo.get();
    bar.get();
    std::cout << "\n\n";

    std::cout << "with launch::deferred .." << std::endl;
    foo = std::async(std::launch::deferred, print_ten, 'C', 100);
    bar = std::async(std::launch::deferred, print_ten, 'Z', 200);
    foo.get();
    bar.get();
    std::cout << "\n\n";
    return 0;
}
