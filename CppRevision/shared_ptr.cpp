#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::shared_ptr<int> p1 = std::make_shared<int>();
    *p1 = 14;
    std::cout << "*p1 = " << *p1 << std::endl;

    std::cout << "p1 reference count: " << p1.use_count() << std::endl;

    std::shared_ptr<int> p2(p1);
    std::cout << "p1 reference count: " << p1.use_count() << std::endl;
    std::cout << "p2 reference count: " << p2.use_count() << std::endl;

    if(p1 == p2){
        std::cout << "p1 and p2 are pointing to same pointer." << std::endl;
    }

    p1.reset();
    std::cout << "p1 reference count: " << p1.use_count() << std::endl;

    p1.reset(new int(20));
    std::cout << "p1 reference count: " << p1.use_count() << std::endl;

    p1 = nullptr; 
    std::cout << "p1 reference count: " << p1.use_count() << std::endl;

    if(!p1) std::cout << "p1 is NULL." << std::endl;

    return 0;
}

