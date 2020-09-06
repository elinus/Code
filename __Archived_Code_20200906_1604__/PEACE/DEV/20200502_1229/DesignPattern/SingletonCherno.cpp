#include <iostream>
#include <cstdlib>
#include <ctime>

class Singleton {
    private:
    static Singleton s_Instance;
    Singleton() = default;
    public:
    ~Singleton() = default;
    Singleton(const Singleton & other) = delete;
    Singleton & operator=(const Singleton & other) = delete;
    void foo(int i) {
        std::cout << "Reached here! i :: " << i << std::endl;
    }
    static Singleton & getInstance() {
        return s_Instance;
    }
};

Singleton Singleton::s_Instance;

int main(int argc, char const *argv[])
{
    srand(time(nullptr));
    for (size_t i = 0; i < 10; i++)
    {
        int rand_ = rand() % 10 + 1;
        Singleton::getInstance().foo(rand_);
    }
    
    return 0;
}
