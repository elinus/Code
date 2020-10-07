#include <iostream>
#include <vector>

struct Test {
    Test() {
        id = ++nextId;
        std::cout << id << " :: Test Constructor\n";
    }
    Test(const Test & other) {
        id = other.id;
        std::cout << id << " :: Test Copy Constructor\n";
    }
    Test & operator=(const Test & other) {
        id = other.id;
        std::cout << id << " :: Test Assignment Operator\n";
        return *this;
    }
    private:
    int id;
    protected:
    static int nextId;
};

int Test::nextId = 0;

int main(int argc, char const *argv[])
{
    std::vector<Test> vecTest;
    std::cout << "Size = " << vecTest.size() << "\n";
    std::cout << "Capacity = " << vecTest.capacity() << "\n";
    int capacity = vecTest.capacity();
    for (size_t i = 0; i < capacity + 1; ++i)
    {
        vecTest.push_back(Test());
    }

    std::cout << "Size = " << vecTest.size() << "\n";
    std::cout << "Capacity = " << vecTest.capacity() << "\n";
    
    capacity = vecTest.capacity();
    for (size_t i = 0; i < capacity + 1; ++i)
    {
        vecTest.push_back(Test());
    }

    std::cout << "Size = " << vecTest.size() << "\n";
    std::cout << "Capacity = " << vecTest.capacity() << "\n";

    capacity = vecTest.capacity();
    for (size_t i = 0; i < capacity + 1; ++i)
    {
        vecTest.push_back(Test());
    }

    std::cout << "Size = " << vecTest.size() << "\n";
    std::cout << "Capacity = " << vecTest.capacity() << "\n";
    return 0;
}
