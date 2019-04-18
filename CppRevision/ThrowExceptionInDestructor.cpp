#include <iostream>
#include <memory>

using namespace std;

class Bar {
    private:
    int *iptr;
    public:
    Bar() {
        cout << "Bar() called" << endl;
        iptr = new int(14);
        // throw "throw something";
    }
    ~Bar() /* throw() */ {
        delete iptr;        
        cout << "~Bar() called" << endl;
        // throw 14;
        // note: in C++11 destructors default to noexcept
    }

};

int main(int argc, char const *argv[])
{
    try {
        cout << "Creating object on stack!" << endl;
        Bar bar;
        cout << "Bar object constructed!" << endl;
        // throw 14;
    } catch (const char *e) {
        cout << "exception caught!!" << endl;
    }

    cout << "\n\n";
    try {
        cout << "Creating object on heap!" << endl;
        Bar *bptr1 = new Bar;
        cout << "Bar object constructed!" << endl;
        // throw 14;
    } catch (const char *e) {
        cout << "exception caught!!" << endl;
    }
    
    cout << "\n\n";
    try {
        cout << "Creating object using unique_ptr!" << endl;
        unique_ptr<Bar> bptr2(new Bar());
        cout << "Bar object constructed!" << endl;
        // throw 14;
    } catch (const char *e) {
        cout << "exception caught!!" << endl;
    } catch (int e) {
        cout << "[int] exception caught!!" << endl;
    }
    return 0;
}
