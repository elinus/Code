#include <iostream>
#include <memory>

class Test {
    private:
        int value;
    public:
        Test(int value) : value(value)
        {
            std::cout << "Constructor" << std::endl;
        }
        ~Test()
        {
            std::cout << "Destructor" << std::endl;
        }
        int getValue() { return value; }
};

int main (int argc, char *argv[])
{
    std::unique_ptr<Test> p1;
    if (!p1) {
        std::cout << "p1: Empty" << std::endl;
    }
    if (p1 == nullptr) {
        std::cout << "p1: Empty" << std::endl;
    }

    //std::unique_ptr<Test> p2 = new Test(14); 
        // error: conversion from ‘Test*’ to non-scalar type ‘std::unique_ptr<Test>’ requested
    std::unique_ptr<Test> p3(new Test(14));
    std::cout << p3->getValue() << std::endl;
    
    //error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Test; _Dp = std::default_delete<Test>]’
    //std::unique_ptr<Test> p4(p3);

    p3.reset();

    {
        std::unique_ptr<Test> p5(new Test(20));
        std::cout << "p5 = " << p5.get() << " p5->getValue() = " << p5->getValue() << "\n";
        std::unique_ptr<Test> p6 = std::move(p5);
        if (p5 == nullptr) {
            std::cout << "p5: Empty" << std::endl;
        }
        std::cout << "p6 = " << p6.get() << " p6->getValue() = " << p6->getValue() << "\n";
        
        p6.release(); //relaease ownership of raw ptr
        if (p6 == nullptr) {
            std::cout << "p6: Empty" << std::endl;
        }
        std::cout << "Exit block scope.." << std::endl;
    }
    std::cout << "Exit main func.." << std::endl;
    return 0;
}

