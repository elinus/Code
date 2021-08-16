#include <iostream>
#include <memory>

class Resource {
    public:
        Resource() { std::cout << "[" << this <<"] Resource acquired\n"; }
        ~Resource() { std::cout << "[" << this << "] Resource released\n"; }
};

std::unique_ptr<Resource> foo() {
    return std::make_unique<Resource>();
}

int main(int argc, char const *argv[]) {
    std::unique_ptr<Resource> res1(new Resource);
    std::unique_ptr<Resource> res2;
    
    std::cout << "res1 is " << (static_cast<bool>(res1) ? "non null" : "null") << std::endl;
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
    res2 = std::move(res1);
    std::cout << "----- move -----\n";
    std::cout << "res1 is " << (static_cast<bool>(res1) ? "non null" : "null") << std::endl;
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
        
    // make_unique
    std::cout << "\n\n----- make_unique -----\n";
    std::unique_ptr<Resource> res3 = std::make_unique<Resource>();
    std::cout << "res3 is " << (static_cast<bool>(res3) ? "non null" : "null") << std::endl;
    // reset
    res3.reset();
    std::cout << "----- reset -----\n";
    std::cout << "res3 is " << (static_cast<bool>(res3) ? "non null" : "null") << std::endl;


    std::cout << "\n\n";
    // release
    Resource *ptr1 = res2.get();
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
    std::cout << "ptr1 = " << ptr1 << std::endl;
    Resource *ptr2 = res2.release();
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "non null" : "null") << std::endl;
    std::cout << "ptr2 = " << ptr2 << std::endl;
    
    std::cout << "\n\n";
    std::unique_ptr<Resource> ptr = foo();
    std::cout << "ptr is " << (static_cast<bool>(ptr) ? "non null" : "null") << std::endl;

    
    std::cout << "\n\n";
    std::unique_ptr<Resource[]> resArr(new Resource[5]); 
    return 0;
}

