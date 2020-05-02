#include <iostream>
#include <typeinfo>

template<typename T>
T Sum(T *arr, int size) {
    std::cout << typeid(T).name() << "\n";
    T sum {};
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

template<typename T, int size>
T Sum(T (&arr)[size]) {
    std::cout << "ref :: " << typeid(T).name() << "\n";
    T sum {};
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main (int argc, char *argv[]) {
    int arr[] = {14, 20, 25, 11, 16};
    std::cout << Sum(arr, 5) << std::endl;
    std::cout << Sum(arr) << std::endl;
    return 0;
}

