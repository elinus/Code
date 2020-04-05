#include<iostream> 

class Base { 
    private: 
        virtual void foo() { std::cout << "Base - Foo\n"; } 
    friend int main(); /* If this is commented */
	// error: 'foo' is a private member of 'Base' 
}; 

class Derived : public Base { 
    public: 
        void foo() { std::cout << "Derived Foo\n"; } 
}; 

int main() 
{ 
    Base *ptr = new Derived; 
    ptr->foo(); 
    return 0; 
} 
