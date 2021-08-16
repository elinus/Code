#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

class Base {
    public:
    Base() {
        cout << "Base = " << this << endl;
    }
    void foo() {
        cout << "foo() from base: " << this << endl;
    }
};

class Derived : public Base {
    public:
    Derived() {
        cout << "Derived = " << this << endl;
    }
    void bar() {
        cout << "bar() from derived: " << this << endl;
    }
};

class Unrelated {
    public:
    Unrelated() {
        cout << "Unrelated = " << this << endl;
    }
    void fizz() {
        cout << "fizz() from unrelated: " << this << endl;
    }
};

int main(int argc, char const *argv[])
{
    Base *bo1 = new Base();
    Derived *do1 = new Derived();
    bo1->foo();
    do1->foo();
    do1->bar();
    cout << "typeid of bo1 = " << typeid(bo1).name() << endl;
    cout << "typeid of do1 = " << typeid(do1).name() << endl;
    // static_cast
    // Not safe as Derived can contain members not in Base
    Derived *do2 = static_cast<Derived*>(bo1); 
    do2->foo();
    do2->bar(); 
    // Safe as Derived Contains Base public members from inheritance.
    Base *bo2 = static_cast<Base*>(do1); 
    bo2->foo();
    cout << "typeid of bo2 = " << typeid(bo2).name() << endl;
    cout << "typeid of do2 = " << typeid(do2).name() << endl;
    
    int myint = 5;
    cout << "The type of myint is " << typeid(myint).name() << " with value " << myint << endl;
    //Cast int to double, safe as precision of double is greater.
    double mydouble = static_cast<double>(myint);
    printf("The type of mydouble is %s with value %f \n",typeid(mydouble).name(), mydouble);

    cout << "\n\n";

    // dynamic_cast
    Derived *do3 = new Derived;
    Base *bo3 = dynamic_cast<Base*>(do3);
    cout << "typeid of do2 = " << typeid(do3).name() << endl;
    cout << "typeid of bo3 = " << typeid(bo3).name() << endl;
    
    // Not Allowed: Error => cannot dynamic_cast 'bo4' (of type 'class Base*') to type 'class Derived*' (source type is not polymorphic)
    // Base *bo4 = new Base;
    // Derived *do4 = dynamic_cast<Derived*>(bo4);

    // const_cast
    const int myconst = 5;
    volatile int myvolatile = 9;
    int* nonconst = const_cast<int*>(&myconst);
    int* nonvolatile = const_cast<int*>(&myvolatile);

    cout << "\n\n";
    // reinterpret_cast
    Base *bo5 = new Base;
    Unrelated *uo1 = new Unrelated;
    //Possibly unsafe cast.
    Base *bo6 = reinterpret_cast<Base*>(uo1);
    cout << "The type of bo6 is: " << typeid(bo6).name() << endl;
    (*bo6).foo();

    return 0;
}
