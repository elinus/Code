#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &A) {
    if (A.empty())
      return {};
    if (A.size() == 1)
      return A[0];
    vector<int> result;
    if (A[0].size() == 1) {
      for (int i = 0; i < A.size(); i++) {
        result.push_back(A[i][0]);
      }
      return result;
    }
    int R = A.size(), C = A[0].size();
    int row_s = 0, col_s = 0, row_e = R - 1, col_e = C - 1;
    while (row_s <= row_e && col_s <= col_e) {
      for (int l = row_s; l <= col_e; l++) {
        result.push_back(A[row_s][l]);
      }
      row_s++;

      for (int d = row_s; d <= row_e; d++) {
        result.push_back(A[d][col_e]);
      }
      col_e--;

      if (row_s <= row_e) {
        for (int r = col_e; r >= col_s; r--) {
          result.push_back(A[row_e][r]);
        }
        row_e--;
      }

      if (col_s <= col_e) {
        for (int u = row_e; u >= row_s; u--) {
          result.push_back(A[u][col_s]);
        }
        col_s++;
      }
    }
    return result;
  }
};