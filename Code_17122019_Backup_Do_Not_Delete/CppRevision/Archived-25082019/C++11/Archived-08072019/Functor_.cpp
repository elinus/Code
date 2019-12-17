/*
 @note:
 - Functor is kind of Callback with state
 * */

#include <iostream>

class Functor_ {
public:
  int operator()(int a, int b) { return a + b; }
};

class Encrypt {
private:
  bool increment;
  int count;

public:
  Encrypt() {
    increment = true;
    count = 1;
  }

  Encrypt(bool increment, int count) {
    this->increment = increment;
    this->count = count;
  }

  std::string operator()(std::string data) {
    for (int i = 0; i < data.size(); i++) {
      if (increment) {
        data[i] += count;
      } else {
        data[i] -= count;
      }
    }
    return data;
  }
};

std::string encrypt_msg(std::string msg, Encrypt encryptObj) {
  msg = "[START]" + msg + "[END]";
  msg = encryptObj(msg);
  return msg;
}

int main(int argc, char *argv[]) {
  Functor_ fo;
  std::cout << fo(14, 20) << std::endl;

  std::cout << encrypt_msg("TestMessage", Encrypt(true, 2)) << std::endl;
  return 0;
}
