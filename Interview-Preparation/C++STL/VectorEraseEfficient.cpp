#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 5, 4, 5, 1, 5, 7, 8, 9};
    
    // Erase all occurence of 4, Inefficient method
    // auto it = vec.begin();
	// while(it != vec.end())
	// {
	// 	if(*it == 5)
	// 	{
	// 		it = vec.erase(it);
	// 	}
	// 	else
	// 		it++;
	// }

    // Efficent method
    vec.erase(std::remove(vec.begin(), vec.end(), 5), vec.end());

    for (auto i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
     
    return 0;
}
