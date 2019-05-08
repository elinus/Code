#include <iostream>

using namespace std;

class Base {
    public:
        virtual ~Base() {
            cout << __func__ << endl;
        }
};

class Derived : public Base {
    public:
        ~Derived() {
            cout << __func__ << endl;
        }
};

int main (int argc, char const *argv[])
{
    Derived *dptr = new Derived;
    Base *bptr = dptr;
    delete bptr;
    return 0;
}

