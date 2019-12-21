#include <iostream>

class IntPair {
    public:
        int mX, mY;

        void set(int x, int y) {
            mX = x;
            mY = y;
        }
        void print() {
            std::cout << "Pair(" << mX << ", " << mY << ")\n";
        }
};

int main (int argc, char *argv[]) {
    
    IntPair p1;
    p1.set(1, 1);

    IntPair p2 {2, 2};

    p1.print();
    p2.print();

    return 0;
}

