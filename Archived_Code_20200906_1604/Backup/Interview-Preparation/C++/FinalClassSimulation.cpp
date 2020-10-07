#include <iostream>

class Final;

class MakeFinal {
    private:
        MakeFinal() {
            std::cout << "MakeFinal Constructed!" << std::endl;
        }
    friend class Final;
};

class Final : virtual MakeFinal {
    public:
        Final() {
            std::cout << "Final Constructed!" << std::endl;
        }
};

/*
class Derived : public Final {
    public:
        Derived() {
            std::cout << "Derived!" << std::endl;
        }
};
*/

int main (int argc, char *argv[]) {
    Final fObj;
    return 0;
}

