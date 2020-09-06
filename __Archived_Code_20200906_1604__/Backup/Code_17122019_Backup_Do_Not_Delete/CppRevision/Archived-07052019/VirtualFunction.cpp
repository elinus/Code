#include <iostream>

using namespace std;

class Base {
    public:
        virtual void print() {
            cout << "Base - print()" << endl;
        }
};

class Derived : public Base {
    public:
        void print() {
            cout << "Dervied - print()" << endl;
        }
};

int main (int argc, char const *argv[])
{
    Base *bp = new Derived;
    bp->print();
    return 0;
}

