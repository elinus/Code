#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// int nCr(int n, int r) {
//   if (r == 0 || n == r)
//     return 1;
//   return nCr(n - 1, r) + nCr(n - 1, r - 1);
// }

vector<vector<int>> solve(int A) {
  vector<vector<int>> vec;
  if (A == 0)
    return vec;
  //   vector<vector<int>> pt;
  //   for (int n = 0; n < A; n++) {
  //     vector<int> v;
  //     for (int r = 0; r < A; r++) {
  //       v.push_back(nCr(n, r));
  //     }
  //     pt.push_back(move(v));
  //   }
  //   return pt;
  std::vector<std::vector<int>> out = {{1}};
  for (int i = 1; i < A; i++) {
    std::vector<int> in;
    in.push_back(1);
    for (int j = 1; j <= i - 1; j++) {
      in.push_back(out[i - 1][j - 1] + out[i - 1][j]);
    }
    in.push_back(1);
    out.push_back(in);
  }
  return out;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
