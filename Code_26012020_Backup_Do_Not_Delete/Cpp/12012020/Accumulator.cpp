#include <iostream>

class Accumulator {
    private:
        int mValue;
    public:
        Accumulator() {
            mValue = 0;
        }
        void add(int value) {
            mValue += value;
        }
        friend void reset(Accumulator &acc);
};

void reset(Accumulator &acc) {
    acc.mValue = 0;
}

int main (int argc, char *argv[]) {
    Accumulator acc;
    acc.add(5);
    reset(acc);
    return 0;
}

