#include <iostream>

void log()
{
    std::cout << "For breaking recursion chain!!" << std::endl;
}

template<typename T, typename ... Args>
void log(T first, Args ... args)
{
    std::cout << first << std::endl;
    log(args ...);
}

int main (int argc, char *argv[])
{
    log(1, 2.4, "5.67");
    return 0;
}

