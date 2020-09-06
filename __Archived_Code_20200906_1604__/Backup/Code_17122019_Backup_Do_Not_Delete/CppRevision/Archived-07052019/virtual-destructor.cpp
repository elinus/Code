#include <iostream>

using namespace std;

class Base {
    public:
        Base() {
            cout << __func__ << endl;
        }
        virtual ~Base() {
            cout << __func__ << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << __func__ << endl;
        }
        ~Derived() {
            cout << __func__ << endl;
        }
};

int main (int argc, char const *argv[])
{
    Derived *dobj = new Derived;
    Base *bobj = dobj;
    delete bobj;
    return 0;
}

