#include <iostream>
#include <algorithm>

void display(int a) {
    std::cout << a << " ";
}

int main (int argc, const char *argv[]) {
    int arr[] = { 1, 2, 3, 4, 5 };
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), display);
    std::cout << std::endl;

    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
            std::cout << x << " ";
            });

    std::cout << std::endl;

}
