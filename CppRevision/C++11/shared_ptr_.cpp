#include <iostream>
#include <memory>

int main (int argc, char *argv[])
{
    std::shared_ptr<int> p1(new int(14));
    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << std::endl;
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;
    
    std::shared_ptr<int> p2(p1);
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl;


    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << std::endl;
    std::cout << "p2 = " << p2 << ", *p2 = " << *p2 << std::endl;

    p1.reset();
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

    p1.reset(new int(20));
    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << std::endl;
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

    p1 = nullptr;
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

    //std::shared_ptr<int> p3 = new int(); //  error: conversion from ‘int*’ to non-scalar type ‘std::shared_ptr<int>’ requested
    std::shared_ptr<int> p3 = std::make_shared<int>();
    return 0;
}

