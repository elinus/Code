#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 

int main(int argc, char const *argv[])
{
    std::vector<int> vec(10);
    for (size_t i = 0; i < 10; i++)
    {
        vec[i] = i + 1;
    }

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    auto it = std::find(vec.begin(), vec.end(), 5);
    it = vec.erase(it); // fix for Iterator Invalidation

    for (;it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    return 0;
}
