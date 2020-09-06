#include <iostream>
#include <unistd.h>

void foo_clean() {
    std::cout << "clean called!\n";
}

int main (int argc, char *argv[]) {
    atexit(foo_clean);
    //exit(0);
    _exit(0);
    return 0;
}

