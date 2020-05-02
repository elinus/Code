#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y;
    std::cout << "Enter another number: ";
    std::cin >> y;

    int op;
    do
    {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int (*pFcn)(int, int) = nullptr;

    // Set pFcn to point to the function the user chose
    switch (op)
    {
        case 0: 
            pFcn = add; 
            break;
        case 1: 
            pFcn = subtract; 
            break;
        case 2: 
            pFcn = multiply; 
            break;
    }

    std::cout << "The answer is: " << pFcn(x, y) << std::endl;

    return 0;
}
