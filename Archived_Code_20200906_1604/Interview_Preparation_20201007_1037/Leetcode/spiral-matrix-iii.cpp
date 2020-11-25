#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> path;
    int count = 0;
    int sequence = 1;
    int row = r0, col = c0, dir = 0;
    vector<int> movex{0, 1, 0, -1};
    vector<int> movey{1, 0, -1, 0};
    path.push_back({r0, c0});
    while (path.size() < (R * C)) {
    //   cout << "#" << sequence << "\n";
      for (int i = 1; i <= sequence; i++) {
        row += movex[dir];
        col += movey[dir];
        // cout << "(" << row << ", " << col << ")\n";
        if (row >= 0 && row < R && col >= 0 && col < C) {
          path.push_back({row, col});
        }
      }
      if (count & 1) {
        sequence++;
      }
      count++;
      dir++;
      dir %= 4;
    }
    return path;
  }
};

int main(int argc, char const *argv[]) {
  //   vector<vector<int>> input_mtx = {
  //       {1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}};
  Solution sol;
  auto mtx = sol.spiralMatrixIII(5, 6, 1, 4);
  for (size_t i = 0; i < mtx.size(); i++) {
    for (size_t j = 0; j < mtx[i].size(); j++) {
      cout << mtx[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
