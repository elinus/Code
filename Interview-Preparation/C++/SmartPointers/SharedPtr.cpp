#include <iostream>
#include <memory>

struct Foo
{
    void bar() {
        std::cout << "** Foo::bar() **\n";
    }
};


int main(int argc, char const *argv[])
{
    std::shared_ptr<int> p1 = std::make_shared<int>();
    *p1 = 14;
    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << "\n";
    std::cout << "p1(use_count) reference count = " << p1.use_count() << "\n";

    std::shared_ptr<int> p2(p1);
    std::cout << "p2 = " << p2 << ", *p2 = " << *p2 << "\n";
    std::cout << "p1 ref. count = " << p1.use_count() << "\n";
    std::cout << "p2 ref. count = " << p2.use_count() << "\n";

    if (p1 == p2)
    {
        std::cout << "p1 and p2 pointing to same memory location\n";
    }

    std::cout << "***** Reset p1 *****\n";
    p1.reset();
    std::cout << "p2 = " << p2 << ", *p2 = " << *p2 << "\n";
    std::cout << "p1 ref. count = " << p1.use_count() << "\n";
    std::cout << "p2 ref. count = " << p2.use_count() << "\n";

    p1.reset(new int(20));
    std::cout << "p1 = " << p1 << ", *p1 = " << *p1 << "\n";
    std::cout << "p1(use_count) reference count = " << p1.use_count() << "\n";

    p1 = nullptr;
    std::cout << "p1 ref. count = " << p1.use_count() << "\n";

    if (p1 == nullptr)
    {
        std::cout << "p1 = nullptr\n";
    }
    
    std::shared_ptr<Foo> ptr = std::make_shared<Foo>();
    (*ptr).bar();
    ptr->bar();
    std::cout << "ptr = " << ptr << ", ref. count = " << ptr.use_count() << "\n";
    Foo *raw_ptr = ptr.get();
    std::cout << "raw_ptr = " << raw_ptr << "\n";
    return 0;
}
