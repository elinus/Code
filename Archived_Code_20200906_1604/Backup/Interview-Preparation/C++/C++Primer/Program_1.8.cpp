#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */";
    std::cout << /* "*/" /* "/*" */;
    return 0;
}

