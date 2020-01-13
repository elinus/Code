#include <iostream>

void foo();
void bar();

#pragma startup foo
#pragma exit bar

void foo() {
    std::cout << __FILE__ << ": " << __func__ << ", " << __LINE__ << "\n";
}

void bar() {
    std::cout << __FILE__ << ": " << __func__ << ", " << __LINE__ << "\n";
}

int main (int argc, char *argv[]) {
    foo();
    bar();
    std::cout << __FILE__ << ": " << __func__ << ", " << __LINE__ << "\n";
    return 0;
}

