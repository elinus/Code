#include <iostream>

extern int g_x;
extern const double g_gravity;
extern const int g_months;

int main (int argc, char *argv[]) 
{
    extern int g_y;
    g_x = 5;
    g_y = 7;
    std::cout << g_x << " " << g_y << "\n";
    //std::cout << g_gravity << "\n";
    return 0;
}

