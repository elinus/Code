#include <iostream>
#include <exception>

class Foo {
    public:
        Foo(){
            char *ptr = new char[99999999999999999];
            delete [] ptr;
        }
};

int main(int argc, char const *argv[])
{
    try {
        Foo fobj;   
    } catch (std::bad_alloc &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

