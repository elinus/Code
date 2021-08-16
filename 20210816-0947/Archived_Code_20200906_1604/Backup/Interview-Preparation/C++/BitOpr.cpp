#include <iostream>

int main (int argc, char *argv[]) {
    
    int number = 3;
    int pos = 2;
    // set
    number |= (1 << pos);
    std::cout << number << "\n";

    // unset/clear
    number = 3;
    pos = 1;
    number &= ~(1 << pos);
    std::cout << number << std::endl;

    // toggle
    number = 3;
    pos = 0;
    number ^= (1 << pos);

    // checking a bit
    number = 3;
    pos = 1;
    int bit = (number >> pos) & 1;

    // changing n'th bit
    number = 3;
    int n = 2;
    int bitVal = 1;
    number = number & ~(1 << n) |  (bitVal << n);

    // Count number of bits
    number = 3;
    int count = 0;
    while (number) {
        count += (number & 1);
        number >>= 1;
    }

    for (count = 0; number; count++) {
        number &= number-1;
    }

    return 0;
}

