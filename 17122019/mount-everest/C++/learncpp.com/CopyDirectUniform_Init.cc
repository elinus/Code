#include <iostream>

int main (int argc, char *argv[]) 
{
    int foo1 = 1.1; // Copy initialization
    int foo2(2.2); // Direct initialization
    std::cout << foo1 << " " << foo2 << std::endl;

    int foo3{3.3}; // Uniform initialization
    // error: narrowing conversion of ‘3.2999999999999998e+0’ from ‘double’ to ‘int’ inside { } [-Wnarrowing]
    return 0;
}

