#include <iostream>
#include <functional>

std::function<void()> getCallBack()
{
    int value = 23;
    auto foo = [&](){
        value = 16;
    };
}

int main (int argc, char *argv[])
{
    int value = 14;
    auto foo1 = [value](){
        std::cout << "inside lambda: " << value << std::endl;
        //value = 20; // error: assignment of read-only variable ‘value’
        std::cout << "inside lambda(changed): " << value << std::endl;
    };
    foo1();
    std::cout << "post lambda: " << value << std::endl;

    std::cout << "-----" << std::endl;
    auto foo2 = [value]() mutable {
        std::cout << "inside lambda: " << value << std::endl;
        value = 20;
        std::cout << "inside lambda(changed): " << value << std::endl;
    };
    foo2();
    std::cout << "post lambda: " << value << std::endl;

    std::cout << "-----" << std::endl;
    auto foo3 = [&value](){
        std::cout << "inside lambda: " << value << std::endl;
        value = 20;
        std::cout << "inside lambda(changed): " << value << std::endl;
    };
    foo3();
    std::cout << "post lambda: " << value << std::endl;

    auto foo4 = [&](){}; // capture all variables by ref
    auto foo5 = [=](){}; // all by value
    //std::function<void()> func = getCallBack();
    //func(); //  SIGSEGV, Segmentation fault

    return 0;
}

