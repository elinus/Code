#include <iostream>
#include <memory>
#include <cassert>

void foo(std::unique_ptr<int> uptr) {
    std::cout << __func__ << ": " << *uptr << std::endl;
}

std::unique_ptr<int> bar() {
    std::unique_ptr<int> buptr = std::make_unique<int>(14); 
    return buptr;
}

int main (int argc, char const *argv[])
{
    std::unique_ptr<int> p1(new int(14));
    std::cout << *p1 << std::endl; 
    assert(p1); // p1 != nullptr
    foo(std::move(p1));
    assert(!p1); // p1 == nullptr
   
    auto p2 = bar();
    std::cout << *p2 << std::endl; 

    return 0;
}

