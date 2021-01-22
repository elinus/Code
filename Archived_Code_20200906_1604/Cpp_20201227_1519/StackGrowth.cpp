#include <iostream>

using namespace std;

int *foo_ptr = nullptr;
int *main_ptr = nullptr;

void foo() {
    int a;
    foo_ptr = &a;
}

int main (int argc, const char *argv[]) {
    int a;
    main_ptr = &a;
    foo();
    main_ptr > foo_ptr ? cout << "Down!\n" : cout << "up!\n";
    return 0;
}

