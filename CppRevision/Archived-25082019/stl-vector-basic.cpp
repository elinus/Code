#include <iostream>
#include <vector>

int main (int argc, char const *argv[])
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "sizeof(vec) = " << vec.size() << std::endl;
    for (const int i: vec) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
    std::cout << "data = " << vec.data() << std::endl;
    std::cout << "vec.begin() = " << *(vec.begin()) << std::endl;
    std::cout << "vec.end() - 1 = " << *(vec.end() - 1) << std::endl;
    std::cout << "vec.rbegin() = " << *(vec.rbegin()) << std::endl;
    std::cout << "vec.rend()++ = " << *(vec.rend()++) << std::endl;
    std::cout << "vec.empty() = " << vec.empty() << std::endl;
    std::cout << "vec.front() = " << vec.front() 
        << ", vec.back = " << vec.back() << std::endl;
    for (int i = 0; i < 5; i++) {
        vec.pop_back();
    }
    for (int i = 14; i <= 20; i++) {
        vec.emplace(vec.begin(), i);
    }
    for (int i = 11; i <= 16; i++) {
        vec.emplace_back(i);
    }
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::vector<int> myVec = {14, 20, 24, 11, 16};
    myVec.swap(vec);
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "myvec.size() = " << myVec.size() << std::endl;
    std::cout << "myvec.capacity() = " << myVec.capacity() << std::endl;
    myVec.clear();
    std::cout << "myvec.size() = " << myVec.size() << std::endl;
    std::cout << "myvec.capacity() = " << myVec.capacity() << std::endl;
    myVec.shrink_to_fit();
    std::cout << "myvec.size() = " << myVec.size() << std::endl;
    std::cout << "myvec.capacity() = " << myVec.capacity() << std::endl;
    myVec.reserve(10);
    std::cout << "myvec.size() = " << myVec.size() << std::endl;
    std::cout << "myvec.capacity() = " << myVec.capacity() << std::endl;
    return 0;
}

