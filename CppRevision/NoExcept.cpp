#include <iostream>
/*
 * NoExcept.cpp:4:12: warning: throw will always call terminate() [-Wterminate]
 *     throw -1;
 * ----------------------------------------------------------------------------
 *  terminate called after throwing an instance of 'int'
 *  Aborted (core dumped)
 */
//void foo() noexcept {
//    throw -1;
//}

void bar() noexcept(false) {
    throw -1;
}

int main(int argc, char const *argv[]) {
    try {
        bar();
        //foo();
    } catch (int) {
        std::cerr << "Exception caught!" << std::endl;
    }
    return 0;
}

