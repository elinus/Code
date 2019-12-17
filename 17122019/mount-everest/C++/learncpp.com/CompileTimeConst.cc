#include <iostream>

int main (int argc, char *argv[]) 
{
    /* Compile time constant */
    constexpr double gravity{9.8};
    constexpr int sum{14 + 20};
    std::cout << gravity << " " << sum << "\n";

    /* Runtime constant */
    int age;
    std::cout << "age: ";
    std::cin >> age;
    const int userAge {age };
    std::cout << userAge << "\n";
    return 0;
}

