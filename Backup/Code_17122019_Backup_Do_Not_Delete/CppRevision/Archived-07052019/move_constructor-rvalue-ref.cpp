#include <iostream>
#include <vector>

using namespace std;

class Container {
    public:
        Container(): ptr(new int[20]) {
            cout << "Constructor = " << this << endl;
        }
        ~Container() {
            cout << "Destructor = " << this << endl;
            if (ptr) {
                delete [] ptr;
                ptr = nullptr;
            }
        }
        Container(const Container &other) {
            cout << "Copy constructor" << endl;
            ptr = new int[20];
            for (int i = 0; i < 20; i++) {
                ptr[i] = other.ptr[i];
            }
        }
        Container(Container && other) {
            cout << "Move constructor" << endl;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        Container& operator =(const Container &other) {
            cout << "Assignment operator" << endl;
            if (this != &other) {
                ptr = new int[20];
                for (int i = 0; i < 20; i++) {
                    ptr[i] = other.ptr[i];
                }
            }
            return *this;
        }
        Container& operator =(Container && other) {
            cout << "Move assignment operator" << endl;
            if (this != &other) {
                ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }
    private:
        int *ptr;
};

Container getContainer() {
    Container obj;
    return obj;
}

int main (int argc, char const *argv[])
{
    vector<Container> vecContainer;
    vecContainer.push_back(getContainer());
    cout << "-- ASSIGN -- " << endl;
    Container obj;
    obj = getContainer();
    return 0;
}

