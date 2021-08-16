#include <iostream>

using namespace std;

class Foo {
    private:
        int i;
    public:
        Foo() = default;
        void print() {
            cout << i << "\n";
        }
};

class Bar {
    private:
        int i;
    public:
        Bar() {}
        void print() {
            cout << i << "\n";
        }
};

int main (int argc, const char *argv[]) {
    
    Foo foo{};
    foo.print();

    Bar bar{};
    bar.print();

    return 0;
}

