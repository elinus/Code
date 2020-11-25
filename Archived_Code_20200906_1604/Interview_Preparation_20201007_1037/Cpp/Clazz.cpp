#include <iostream>

class ClazzA {
    public:
        virtual void foo(){}
        void bar() {}
};

class ClazzB : public ClazzA {
    public:
        void foo() {}
        void fizz() {}
};

int main (int argc, const char *argv[]) {
    ClazzB *bObj = new ClazzB;
    bObj->foo();
    bObj->fizz();
    ClazzA *aObj = bObj;
    aObj->foo();
    aObj->bar();
    return 0;
}

