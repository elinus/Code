#include <iostream>
#include <bitset>

int main (int argc, char *argv[]) 
{
    std::bitset<8> mybitset { 14 };
    std::cout << mybitset << "\n";

    std::bitset<8> bits {0b0000101};
    std::cout << bits << "\n";
    bits.set(3);
    std::cout << bits << "\n";
    bits.flip(4);
    std::cout << bits << "\n";
    bits.reset(4);
    std::cout << bits << "\n";
    
    std::cout << bits.test(3) << "\n";
    std::cout << bits.test(4) << "\n\n";
    
    /* Bit shifting */
    std::bitset<4> x {0b1100};
    std::cout  << x << "\n";
    std::cout << (x << 1) << "\n";
    std::cout << (x >> 1) << "\n";
    
    // Bitwise NOT
    std::cout << std::bitset<4>(~0b0100u) << " " << std::bitset<8>(~0b0100u) << "\n";
    // OR
    std::cout << std::bitset<4>(0b0101u) << " | " <<  std::bitset<4>(0b0110u) << " = ";
    std::cout << (std::bitset<4>(0b0101u) | std::bitset<4>(0b0110u)) << "\n";
    // AND
    std::cout << std::bitset<4>(0b0101u) << " & " <<  std::bitset<4>(0b0110u) << " = ";
    std::cout << (std::bitset<4>(0b0101u) & std::bitset<4>(0b0110u)) << "\n";
    // XOR
    std::cout << std::bitset<4>(0b0110u) << " ^ " <<  std::bitset<4>(0b0011u) << " = ";
    std::cout << (std::bitset<4>(0b0110u) ^ std::bitset<4>(0b0011u)) << "\n";
    return 0;
}

