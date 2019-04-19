#include <iostream>

using namespace std;

class ExplicitConversion {
    public:
    explicit ExplicitConversion(float value): value{value} {};
    void print(const ExplicitConversion ecObj) {
        cout << "[EC]value: " << ecObj.value << endl;
    }
    private:
    float value;
};

class Conversion {
    public:
    Conversion(float value): value{value} {};
    void print(const Conversion cObj) {
        cout << "[C]value: " << cObj.value << endl;
    }
    private:
    float value;
};


int main(int argc, char const *argv[])
{
    ExplicitConversion eco(14.14);
    Conversion co(20.20);
    eco.print(eco);
    double d = 24.11;
    eco.print((ExplicitConversion)d);
    co.print(d);
    return 0;
}
