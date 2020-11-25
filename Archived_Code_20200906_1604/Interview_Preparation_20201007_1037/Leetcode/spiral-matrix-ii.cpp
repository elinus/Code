#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0)
      return {{}};
    if (n == 1)
      return {{1}};
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int i = 1;
    int row_s = 0, col_s = 0, row_e = n - 1, col_e = n - 1;
    while (row_s <= row_e && col_s <= col_e) {
      for (int l = row_s; l <= col_e; l++) {
        matrix[row_s][l] = i++;
      }
      row_s++;

      for (int d = row_s; d <= row_e; d++) {
        matrix[d][col_e] = i++;
      }
      col_e--;

      if (row_s <= row_e) {
        for (int r = col_e; r >= col_s; r--) {
          matrix[row_e][r] = i++;
        }
        row_e--;
      }

      if (col_s <= col_e) {
        for (int u = row_e; u >= row_s; u--) {
          matrix[u][col_s] = i++;
        }
        col_s++;
      }
    }
    return matrix;
  }
};

int main() {
  Solution sol;
  auto mtx = sol.generateMatrix(3);
  for (auto i = 0; i < mtx.size(); i++) {
      for (auto j = 0; j < mtx[i].size(); j++) {
          cout << mtx[i][j] << " ";
      }
      cout << "\n";
  }
  return 0;
}
