#include <iostream>
#include <thread>
#include <string>

void foo(int x, std::string str) {
    std::cout << "tid = " << std::this_thread::get_id() 
        << ", int = " << x 
        << ", string = " << str << std::endl; 
}

void bar(int const & x) {
    int & y = const_cast<int &>(x);
    y++;
    std::cout << "inside thread = " << std::this_thread::get_id() << ", x = " << x << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(foo, 14, "elinus!");
    if (t1.joinable()) {
        t1.join();
    }
    std::cout << "CHECKPOINT #1 :: " << std::this_thread::get_id() << std::endl;
    
    int x = 14;
    std::cout << "in main(before), x = " << x << std::endl;
    std::thread t2(bar, std::ref(x));
    if (t2.joinable()) {
        t2.join();
    }
    std::cout << "in main(after), x = " << x << std::endl;
    
    std::cout << "CHECKPOINT #2 :: " << std::this_thread::get_id() << std::endl;

    std::cout << "exiting tid = " << std::this_thread::get_id() << std::endl;
    return 0;
}

