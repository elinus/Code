#include <iostream>
#include <memory>

class Resource {
    public:
        std::weak_ptr<Resource> mResourcePtr;
        Resource() { std::cout << "[" << this <<"] Resource acquired\n"; }
        ~Resource() { std::cout << "[" << this << "] Resource released\n"; }
};

int main(int argc, char const *argv[]) {

    // make_shared
    std::cout << "----- make_shared -----\n";
    std::shared_ptr<Resource> res = std::make_shared<Resource>();
    std::cout << "res is " << (static_cast<bool>(res) ? "non null" : "null") << std::endl;
    
    res->mResourcePtr = res;
    std::weak_ptr<Resource> weak_res(res);
    std::cout << "weak_res use_count => " << weak_res.use_count() << "\n";
    std::shared_ptr<Resource> res_ = weak_res.lock();
    std::cout << "res_ = " << res_.get() << "\n";

    std::cout << "\n\nexpired => " << weak_res.expired() << "\n";
    res.reset();
    std::cout << "expired => " << weak_res.expired() << "\n";


    return 0;
}

