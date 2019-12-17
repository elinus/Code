#include <boost/scoped_ptr.hpp>
#include <iostream>

int main (int argc, char const *argv[])
{
    boost::scoped_ptr<int> p{new int{14}};
    std::cout << *p << '\n';
    std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
    p.reset(new int{20});
    
    std::cout << *p.get() << '\n';
    p.reset();
    
    std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
    
    return 0;
}

