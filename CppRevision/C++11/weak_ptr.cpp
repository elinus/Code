#include <iostream>
#include <memory>

int main (int argc, char *argv[])
{
    std::shared_ptr<int> p1 = std::make_shared<int>(14);
    std::weak_ptr<int> p2(p1);
    std::shared_ptr<int> p3 = p2.lock();
    
    if (p3) {
        std::cout << *p3 << std::endl;
        std::cout << "ref_count = " << p3.use_count() << std::endl;
    }
    
    if (!p2.expired()) {
        std::cout << "Not expired!" << std::endl;
    }
    return 0;
}

