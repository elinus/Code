#include <iostream>
using namespace std;

// Class template
template <typename T1, typename T2> class Pair {
public:
  T1 first;
  T2 second;
};

// Function template
template <typename T> T minimum(T a, T b) { return a < b ? a : b; }

// Union template
template <typename T> union Test {
  uint8_t ch[sizeof(T)];
  T variable;
};

// Variable template
template <class T> constexpr T pi = T(3.1415926535897932385L);

// {{ Calculate fib value at compile time
template <uint32_t val> constexpr auto fib = fib<val - 1> + fib<val - 2>;

template <> constexpr auto fib<0> = 0;

template <> constexpr auto fib<1> = 1;
// }}

int main(int argc, char const *argv[]) {
  /* class template */
  Pair<int, int> p1;
  Pair<float, float> p2;

  /* function template */
  minimum<int>(4, 5);
  minimum<float>(4.1f, 5.1f);

  cout << pi<float> << endl; // 3.14159
  cout << pi<int> << endl;   // 3

  cout << "fib<10> = " << fib<10> << endl;
  return 0;
}
