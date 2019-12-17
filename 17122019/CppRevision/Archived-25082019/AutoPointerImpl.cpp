#include <iostream>

template<class T>
class AutoPtr {
    private:
        T *m_ptr;
    public:
        AutoPtr(T *ptr = nullptr): m_ptr(ptr) {}
        ~AutoPtr() {
            delete m_ptr;
        }
        T& operator *() const {
            return *m_ptr;
        }
        T* operator ->() const {
            return m_ptr;
        }
        
        AutoPtr(const AutoPtr & other) {
            m_ptr = new T;
            *m_ptr = *other.m_ptr;
        }
        AutoPtr& operator =(const AutoPtr & other) {
            if (this != &other) {
                delete m_ptr;
                m_ptr = new T;
                *m_ptr = *other.m_ptr;
            }
            return *this;
        }        
        AutoPtr(AutoPtr && other): m_ptr(other.m_ptr) {
            other.m_ptr = nullptr;
        }
        AutoPtr& operator =(AutoPtr && other) {
            if (this != &other) {
                delete m_ptr;
                m_ptr = other.m_ptr;
                other.m_ptr = nullptr;
            }
            return *this;
        }
        bool isNull() const {
            return m_ptr == nullptr;
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

void foo(AutoPtr<Test> testObj) {
    std::cout << "foo()" << std::endl;
}

AutoPtr<Test> bar() {
    AutoPtr<Test> testObj(new Test);
    return testObj;
}

int main(int argc, char const *argv[]) {
    //AutoPtr<Test> testObj1(new Test());
    //AutoPtr<Test> testObj2(testObj1);
    //foo(testObj1);
    AutoPtr<Test> test;
    test = bar();
    return 0;
}

