#include <iostream> 
using namespace std; 

class A { 
    public: 
        A() {
            std::cout << "A Constructed!!\n";
        }
        void show() 
        { 
            cout << "Hello form A \n"; 
        } 
}; 

class B : virtual public A { 
    public: 
        B() {
            std::cout << "B Constructed!!\n";
        }
}; 

class C : virtual public A { 
    public: 
        C() {
            std::cout << "C Constructed!!\n";
        }
}; 

class D : public B, public C { 
    public: 
        D() {
            std::cout << "D Constructed!!\n";
        }
}; 

class Base {
    public:
        Base() {
            std::cout << "Base!!" << std::endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived!!" << std::endl;
        }
};

int main() 
{ 
    D object; 
    object.show();

    Derived dObj;
} 
