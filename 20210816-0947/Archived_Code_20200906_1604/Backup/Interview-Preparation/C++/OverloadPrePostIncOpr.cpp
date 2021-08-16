#include <iostream>

class Integer {
    int mInt;
    public:
    Integer()
    {}
    Integer(int val): mInt{val} 
    {}
    ~Integer() {}
    void printInteger() {
        std::cout << mInt << "\n";
    }
    Integer & operator++() {
        ++mInt;
        return *this;
    }
    Integer operator++(int dummy) {
        Integer tmp = *this;
        mInt++;
        return tmp;
    }
};

int main (int argc, char *argv[]) {
    Integer intg(14);
    (intg++).printInteger();
    (++intg).printInteger();

    return 0;
}

