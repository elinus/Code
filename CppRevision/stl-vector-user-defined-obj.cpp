#include <iostream>
#include <vector>

class Test {
    public:
        Test() {
            std::cout << "Test()\n";
        }
        Test(const Test & obj) {
            std::cout << "Test(const Test & obj)\n";
        }
        Test & operator =(const Test & obj) {
            std::cout << "Test & operator =(const Test & obj)\n";
            return *this;
        }
};

int main (int argc, char const *argv[])
{
    std::vector<Test> testVec(2);
    return 0;
}

