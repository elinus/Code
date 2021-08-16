/*
 * g++ Test_buffer-overflow.cpp -fsanitize=address -g
 */
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  const char *name[] = {"foo", "bar"};
  std::string arg = name[2];
  return 0;
}
