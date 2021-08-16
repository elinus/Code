#include <iostream>
#include <typeinfo>

class Account {
public:
  explicit Account(double amt) : balance(amt) {}

private:
  double balance;
};

union WithString {
  std::string s;
  int i;
  WithString() : s("hello") {}
  ~WithString() {}
};

template <typename T> class ClassTemplate {
public:
  ClassTemplate() {
    std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
  }
};

int main() {

  std::cout << std::endl;

  ClassTemplate<int> clTempInt;
  ClassTemplate<double> clTempDouble;
  ClassTemplate<std::string> clTempString;

  ClassTemplate<Account> clTempAccount;
  ClassTemplate<WithString> clTempWithString;

  std::cout << std::endl;
}