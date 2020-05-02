#include <iostream>
#include <typeinfo>
#include <cstring>

template<typename T>
T sum(T arg1, T arg2) {
    std::cout << typeid(T).name() << "\n";
    return arg1 + arg2;
}

template<typename T>
T array_sum(T *arr, int size) {
    T sum {};
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

template<typename T>
T max(T arg1, T arg2) {
    std::cout << typeid(T).name() << "\n";
    return arg1 > arg2 ? arg1 : arg2;
}
// Explicit Instantiation
template char max(char x, char y);

// Explicit Specialization
template<> const char * max(const char * arg1, const char * arg2) {
    std::cout << "Explicit Specialization\n";
    return strcmp(arg1, arg2) > 0 ? arg1 : arg2;
}

int main (int argc, char *argv[]) {
    
    std::cout << sum(14, 20) << "\n";
    std::cout << sum(14.20f, 20.14f) << "\n";
    
    int arr1[] = {14, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    float arr2[] = {14.14, 20.20, 25.25, 11.11, 16.16};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << array_sum(arr1, size1) << "\n";
    std::cout << array_sum(arr2, size2) << "\n";

    const char *a {"A"};
    const char *b {"B"};

    std::cout << max(a, b) << "\n";
    return 0;
}
