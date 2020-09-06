#include <iostream>
#include <chrono>

using namespace std;

template<long N>
long fact() { 
    return N * fact<N-1>();
}

template<>
long fact<0>() {
    return 1;
}

long fact(int N) {
    long f = 1;
    for (int i = N; i >= 1; i--) {
        f *= i;
    }
    return f;
}

int main (int argc, char const *argv[])
{
    auto start1 = std::chrono::system_clock::now();
    std::cout << fact<25>() << std::endl;
    auto end1 = std::chrono::system_clock::now();
    auto diff1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "diff1 = " << diff1.count() << std::endl;

    auto start2 = std::chrono::system_clock::now();
    std::cout << fact(25) << std::endl;
    auto end2 = std::chrono::system_clock::now();
    auto diff2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    std::cout << "diff2 = " << diff2.count() << std::endl;
    
    return 0;
}

