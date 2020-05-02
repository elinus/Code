#include <iostream>
#include <thread>

int main (int argc, char const *argv[])
{
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "Number of cores = " << cores << std::endl;
    return 0;
}

