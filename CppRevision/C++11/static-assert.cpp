#include <iostream> 

using namespace std; 
  
template <class T, int Size> 
class Vector { 
    static_assert(Size > 14, "Vector is too small!");
    T size_[Size];
};

int main (int argc, char const *argv[])
{
    //Vector<int, 14> vec14;
    Vector<int, 20> vec20;
    return 0;
}
