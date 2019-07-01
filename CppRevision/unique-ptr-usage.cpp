#include <iostream>
#include <memory>

int main (int argc, char const *argv[])
{
    std::unique_ptr<int> p1(new int(14));
    std::cout << *p1 << std::endl; 
    return 0;
}

