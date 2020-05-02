#include <iostream>

using namespace std;

class A {};
class B {};

void foo(A *a) {
    cout << "foo() called" << endl;
}

int main (int argc, char const *argv[])
{
    A *a = new A;
    foo(a);
    B *b = new B;
    foo(reinterpret_cast<A*>(b));
    return 0;
}

