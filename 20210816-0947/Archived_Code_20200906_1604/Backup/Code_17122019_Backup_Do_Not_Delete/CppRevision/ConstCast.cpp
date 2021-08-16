#include <iostream>

using namespace std;

void lib(int *x) {
    int k = 14;
    std::cout << *x + k << "\n";
}

int main(int argc, char const *argv[]) {
    const int x = 14;
    const int *px = &x;
    int *p1 = const_cast<int *>(px);
    *p1 = 15; // Undefined
    std::cout << &x << " => " << x << "\n";
    std::cout << px << " => " << *px << "\n";
    std::cout << p1 << " => " << *p1 << "\n";
    // 1
    int y = 20;
    const int *py = &y;
    int *p2 = const_cast<int *>(py);
    std::cout << &y << " => " << y << "\n";
    std::cout << py << " => " << *py << "\n";

    // 2
    lib(const_cast<int *>(px));
    return 0;
}

