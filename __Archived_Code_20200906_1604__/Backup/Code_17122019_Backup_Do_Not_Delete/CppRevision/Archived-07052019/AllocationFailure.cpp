#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        while (true)
        {
            int *iptr = new int[99999ul];
        }
        
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "bad_alloc caught: " << e.what() << '\n';
    }
    
    return 0;
}
