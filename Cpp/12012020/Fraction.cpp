#include <iostream>

class Fraction {
    private:
        int mNum;
        int mDenom;
    public:
        Fraction(int num = 0, int denom = 1)
            : mNum(num), mDenom(denom)
        {}
        int getNumerator() {
            return mNum;
        }
        int getDenominator() {
            return mDenom;
        }
        double getValue() {
            return static_cast<double>(mNum) / mDenom;
        }
};

int main (int argc, char *argv[]) {
    Fraction f1;
    std::cout << f1.getValue() << "\n";
    Fraction f2(14, 20);
    std::cout << f2.getValue() << "\n";
    return 0;
}

