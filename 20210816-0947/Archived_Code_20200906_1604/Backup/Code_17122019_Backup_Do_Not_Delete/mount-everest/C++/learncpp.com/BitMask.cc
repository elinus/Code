#include <iostream>
#include <bitset>

int main (int argc, char *argv[]) 
{
    constexpr unsigned char mask0{ 1 << 0 }; // 0000 0001 
    constexpr unsigned char mask1{ 1 << 1 }; // 0000 0010
    constexpr unsigned char mask2{ 1 << 2 }; // 0000 0100
    constexpr unsigned char mask3{ 1 << 3 }; // 0000 1000
    constexpr unsigned char mask4{ 1 << 4 }; // 0001 0000
    constexpr unsigned char mask5{ 1 << 5 }; // 0010 0000
    constexpr unsigned char mask6{ 1 << 6 }; // 0100 0000
    constexpr unsigned char mask7{ 1 << 7 }; // 1000 0000

    unsigned char flag1 { 0b0000'0101 };
    std::cout << std::bitset<8>(flag1) << "\n";
    std::cout << "bit 0 is " << ((flag1 & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << ((flag1 & mask1) ? "on\n" : "off\n");
    // Setting a bit
    flag1 |= mask1;
    std::cout << "bit 1 is " << ((flag1 & mask1) ? "on\n" : "off\n");
    std::cout << std::bitset<8>(flag1) << "\n";

    unsigned char flag2 { 0b0000'0101 };
    // Restting a bit
    flag2 &= ~mask2;
    std::cout << std::bitset<8>(flag2) << "\n";


    unsigned char flag3 { 0b0000'0101 };
    // Flip a bit
    flag3 ^= ~mask2;
    std::cout << std::bitset<8>(flag3) << "\n";
    
    return 0;
}


