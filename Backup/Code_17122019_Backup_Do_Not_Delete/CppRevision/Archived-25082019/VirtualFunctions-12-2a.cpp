#include <iostream>

using namespace std;

class A {
    public:
        virtual const char* getName() { return "A"; }
        virtual const char* getName1(int x) { return "A"; }
        virtual const char* getName2(int x) { return "A"; }
        virtual void foo() {};
};

class B final : public A {
    public:
        virtual const char* getName() override final { return "B"; }
        //virtual const char* getName1(short int x) { return "B"; }
        
        // error: 'getName1' marked 'override' but does not override any member functions
        // virtual const char* getName1(short int x) override { return "B"; }
        
        // virtual const char* getName2(int x) const override { return "B"; }

        virtual void foo() override {}
};

/*
class C : public B { // error: base 'B' is marked 'final'
    public:
        //error: declaration of 'getName' overrides a 'final' function
        //virtual const char* getName() override { return "C"; }
};
*/


// covariant return types
class Base {
    public:
        virtual Base* getThis() { 
            cout << "Base::getThis" << endl;
            return this; 
        }
        void printType() {
            cout << "Base" << endl;
        }
};

class Derived : public Base {
    public:
        virtual Derived* getThis() { 
            cout << "Derived::getThis" << endl;
            return this; 
        }
        void printType() {
            cout << "Derived" << endl;
        }
};



int main (int argc, char const *argv[])
{
    B bobj;
    A &rAobj = bobj;
    cout << rAobj.getName1(1) << endl;

    Derived d;
    Base &b = d;
    d.getThis()->printType();
    b.getThis()->printType();
    return 0;
}

