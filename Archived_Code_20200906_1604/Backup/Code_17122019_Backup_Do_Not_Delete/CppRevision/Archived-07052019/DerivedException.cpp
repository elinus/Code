#include <iostream>
#include <exception>

using namespace std;

class DerivedException : public exception {
    public:
    virtual const char* what() const throw() {
        return "Derived Exception!!";
    }
} derivedExceptionObject;

int main(int argc, char const *argv[])
{
    try {
        throw derivedExceptionObject;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
