#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4, 5};
  int mul = 14;
  std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), [](int x) {
    std::cout << x << std::endl;
    // mul = 0; // error: ‘mul’ is not captured
  });

  std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]),
                [&](int x) { // Pass by ref
                  std::cout << x << " ";
                  mul = 20;
                });
  std::cout << "\n";

  std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]),
                [=](int x) { // Pass by value
                  std::cout << x << " ";
                  // mul = 20; //error: assignment of read-only variable ‘mul’
                });
  std::cout << "\n";
  return 0;
}
