#include <iostream>
#include <stack>

int main(int argc, char const *argv[]) {
    std::stack<int> s1;
    std::cout << "empty = " << s1.empty() << std::endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    std::cout << "empty = " << s1.empty() << std::endl;
    std::cout << "s1 size = " << s1.size() << std::endl;
    std::cout << "top = " << s1.top() << std::endl;
    
    std::stack<int> s2;
    s2.push(10);
    s2.push(20);
    std::cout << "s2 size = " << s2.size() << std::endl;

    s1.swap(s2);
    std::cout << "s1 size = " << s1.size() 
        << ", s2 size = " << s2.size() << std::endl;

    s1.emplace(30);
    std::cout << "s1 top => " << s1.top() << std::endl;
    s1.pop();
    std::cout << "s1 top => " << s1.top() << std::endl;
    
    return 0;
}

