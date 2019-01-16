#include <iostream>
#include <vector>
#include <initializer_list>
#include <map>

class Test {
    private:
        int x, y;
    public:
        Test(int x, int y) : x(x), y(y)
        {
            std::cout << "constructor with parameter list\n";
        }
        Test(std::initializer_list<int> list)
        {
            if (list.size() == 2) {
                auto it = list.begin();
                x = *it++;
                y = *it;
            }
            std::cout << "constructor initializer list\n";
        }

};

int main (int argc, char *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    Test to1({14, 20});
    Test to2(14, 20);
    
    std::map<std::string, int> mapOfMarks = { { "Riti", 2 }, { "Jack", 4 } };
    for (auto entry : mapOfMarks)
        std::cout << entry.first << " :: " << entry.second << std::endl;
    return 0;
}

