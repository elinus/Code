#include <iostream>
#include <cassert>

class Stack {
    private:
        static constexpr int mMaxStackLength { 10 };
        int mArray[mMaxStackLength];
        int mTop = 0;
    public:
        void reset() {
            mTop = 0;
        }
        bool push(int value) {
            if (mTop == mMaxStackLength) 
                return false;
            mArray[mTop++] = value;
            return true;
        }
        int pop() {
            assert(mTop > 0 && "Cannot pop empty stack!");
            return mArray[--mTop];
        }
        void print() {
            std::cout << "( ";
            for (int i {0}; i < mTop; i++) {
                std::cout << mArray[i] << " ";
            }
            std::cout << ")\n";
        }

};

int main (int argc, char *argv[]) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    stack.pop();
    stack.print();
    return 0;
}

