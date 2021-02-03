#include <iostream>
#include <vector>

using namespace std;

// 2. Type aliases
template <typename T> using dynamic_arr = std::vector<T>;
using func_ptr = int (*)(int);

// 3. User-defined literals
using ull = unsigned long long;

constexpr ull operator"" _KB(ull no) { return no * 1024; }
constexpr ull operator"" _MB(ull no) { return no * (1024_KB); }

int main(int argc, char const *argv[]) {
  // 1. Digit separators
  int no = 1'000'000'000;
  long addr = 0xA000'EFFF;
  uint32_t binary = 0b0001'0010'0111'1111;
  cout << no << "\n" << addr << "\n" << binary << "\n";

  // 2
  dynamic_arr<int> nums;
  cout << "dynamic arr size = " << nums.size() << "\n";

  // 3
  cout << 1_KB << endl;
  cout << 5_MB << endl;

  return 0;
}
