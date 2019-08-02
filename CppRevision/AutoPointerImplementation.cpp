#include <iostream>

template<class T>
class AutoPtr {
    private:
        T *m_ptr;
    public:
        AutoPtr(T *ptr): m_ptr(ptr) {}
        ~AutoPtr() {
            delete m_ptr;
        }
        T& operator *() const {
            return *m_ptr;
        }
        T* operator ->() const {
            return m_ptr;
        }
};

class Test {
    public:
        Test() {
            std::cout << "Test() => Constructor" << std::endl;
        }
        ~Test() {
            std::cout << "~Test() => Destructor" << std::endl;
        }
};

int main(int argc, char const *argv[]) {
    AutoPtr<Test> testObj(new Test());
    return 0;
}

