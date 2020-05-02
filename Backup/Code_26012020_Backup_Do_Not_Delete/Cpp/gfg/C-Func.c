#include <stdio.h>

void foo() {
    printf("Inside foo function!!\n");
}

void fizz(void) {
    printf("Inside fizz function!!\n");
}

int main (int argc, char *argv[]) {
    int bar = 1;
    foo(bar);
    //fizz(bar); // Not allowed
    fizz();
    return 0;
}

