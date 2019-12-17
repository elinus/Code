#include <array>
#include <iostream>

void print(std::array<int, 10> &arr) {
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  std::array<int, 10> arr1;
  print(arr1);

  std::array<int, 10> arr2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(arr2);

  std::array<int, 10> arr3{14, 20};
  print(arr3);

  std::array<int, 10> arr4;
  arr4.fill(24);
  print(arr4);

  std::cout << arr2.at(2) << std::endl;
  std::cout << arr2[2] << std::endl;

  try {
    arr1.at(10);
  } catch (const std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::get<2>(arr2) << std::endl;
  std::cout << arr2.size() << std::endl;
  return 0;
}
