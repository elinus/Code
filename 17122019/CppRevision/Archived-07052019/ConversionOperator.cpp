#include <iostream>

using namespace std;

class Foo {
    public:
    operator int() {
        return 14;
    }
    explicit operator double() {
        return 14.20;
    }
};

int main(int argc, char const *argv[])
{
    Foo foo;
    int i = foo;
    double d1 = foo;
    cout << "i = " << i << ", d1 = " << d1 << endl;
    double d2 = (double)foo;
    cout << "i = " << i << ", d2 = " << d2 << endl;
    return 0;
}
