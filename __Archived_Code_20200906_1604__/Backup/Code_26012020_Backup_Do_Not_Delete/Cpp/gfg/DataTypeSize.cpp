#include <iostream>

#define SIZEOF(x) std::cout << #x << " : " << sizeof(x) << "\n"

int main (int argc, char *argv[]) {

    SIZEOF(short int);
    SIZEOF(unsigned short int);
    SIZEOF(unsigned int);
    SIZEOF(int);
    SIZEOF(long int);
    SIZEOF(unsigned long int);
    SIZEOF(long long int);
    SIZEOF(unsigned long long int);
    SIZEOF(signed char);
    SIZEOF(unsigned char);
    SIZEOF(float);
    SIZEOF(double);
    SIZEOF(long double);
    SIZEOF(wchar_t);

    return 0;
}

