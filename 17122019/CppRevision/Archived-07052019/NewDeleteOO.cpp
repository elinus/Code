#include <iostream> 
#include <new>

using namespace std;

class MyAllocator {
    public:
    MyAllocator() {}
    ~MyAllocator() {}
    static void* operator new (size_t size); 
    static void operator delete(void *p);
};

void* MyAllocator::operator new(size_t size) {
    cout << "operator new called" << endl;
    void *p;
    p = malloc(size);
    if (p == nullptr)
    {
        std::bad_alloc ex;
        throw ex;
    }
    return p;
}

void MyAllocator::operator delete (void *p){
    cout << "operator delete called. " << endl;
    delete[] p;
}

int main(int argc, char const *argv[])
{
    MyAllocator *obj = new MyAllocator();
    delete obj;
    return 0;
}
