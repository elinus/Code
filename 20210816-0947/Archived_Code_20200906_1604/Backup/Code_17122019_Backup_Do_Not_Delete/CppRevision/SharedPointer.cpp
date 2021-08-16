#include <iostream>
#include <memory>

class Resource {
    public:
        Resource() { std::cout << "[" << this <<"] Resource acquired\n"; }
        ~Resource() { std::cout << "[" << this << "] Resource released\n"; }
};

std::shared_ptr<Resource> foo() {
    return std::make_shared<Resource>();
}

int main(int argc, char const *argv[]) {
    std::shared_ptr<Resource> res1(new Resource);
    std::shared_ptr<Resource> res2(res1);

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "non null" : "null") << std::endl;
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
    std::cout << "res1 = " << res1.get() << ", res2 = " << res2.get() << "\n";
    std::cout << "use_count() => res1(" << res1.use_count() 
        << ") res2(" << res2.use_count() << ")\n";
    res1.reset();
    std::cout << "use_count() => res1(" << res1.use_count() 
        << ") res2(" << res2.use_count() << ")\n";

    // make_shared
    std::cout << "\n\n----- make_shared -----\n";
    std::shared_ptr<Resource> res3 = std::make_shared<Resource>();
    std::cout << "res3 is " << (static_cast<bool>(res3) ? "non null" : "null") << std::endl;
    // reset
    res3.reset();
    std::cout << "----- reset -----\n";
    std::cout << "res3 is " << (static_cast<bool>(res3) ? "non null" : "null") << std::endl;

    std::cout << "\n\n";
    Resource *ptr1 = res2.get();
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
    std::cout << "ptr1 = " << ptr1 << std::endl;

    std::cout << "\n\n";
    std::shared_ptr<Resource> ptr = foo();
    std::cout << "ptr is " << (static_cast<bool>(ptr) ? "non null" : "null") << std::endl;
    ptr = nullptr;

    std::cout << "\n\n";
    std::shared_ptr<Resource[]> resArr(new Resource[2]); 

    return 0;
}

