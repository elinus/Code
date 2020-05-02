#include <iostream>

using namespace std;

void foo() noexcept {
    cout << "foo() noexcept" << endl;
    // throw 0;
    // warning: throw will always call terminate() [-Wterminate]
}

void bar() noexcept(false) {
    cout << "bar() noexcept(true)" << endl;
    throw "random exception";
}

int main(int argc, char const *argv[])
{
    foo();

    try
    {
        bar();
    }
    catch(const char *e)
    {
        std::cout << "Exception caught !!!" << '\n';
    }
    
    return 0;
}
