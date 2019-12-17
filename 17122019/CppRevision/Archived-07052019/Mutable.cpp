#include <iostream>
#include <string>

using namespace std;

class Foo {
    public:
    Foo(string msg = ""): msg(msg) {}
    void print() const {
        cout << "msg = " << msg << endl;
    }
    void change(string str) const {
        msg = str;
    }
    private:
    mutable string msg;
};

int main(int argc, char const *argv[])
{
    const Foo foo("foo");
    foo.print();
    foo.change("bar");
    return 0;
}
