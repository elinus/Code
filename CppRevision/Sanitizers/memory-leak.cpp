/*
 * g++ Test_buffer-overflow.cpp -fsanitize=address -g
 */
#include <iostream>

int main(int argc, char *argv[]) {
  int *ptr = new int[10];
  ptr = nullptr;
  return 0;
}
