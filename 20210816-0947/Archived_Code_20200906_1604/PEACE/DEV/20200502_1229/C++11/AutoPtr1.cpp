#include <iostream>

template<class T>
class AutoPtr {
    private:
    T *m_Ptr;
    public:
    AutoPtr(T* ptr = nullptr)
        : m_Ptr { ptr }
    {}
    ~AutoPtr() {
        if (m_Ptr) {
            delete m_Ptr;
        }
    }
    T& operator*() const {
        return *m_Ptr;
    }
    T* operator->() const {
        return m_Ptr;
    }
};

class Resource {
    public:
    Resource() {
        std::cout << "Resource created\n";
    }
    ~Resource() {
        std::cout << "Resource destroyed\n";
    }
};

int main(int argc, char const *argv[])
{
    AutoPtr<Resource> res1 { new Resource() };
    AutoPtr<Resource> res2(res1);
    return 0;
}
