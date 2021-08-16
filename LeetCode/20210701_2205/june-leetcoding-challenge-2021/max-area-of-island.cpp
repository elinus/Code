#include <bits/stdc++.h>
using namespace std;

class Solution {
  int row = 0;
  int col = 0;
  vector<int> xaxis{1, 0, -1, 0};
  vector<int> yaxis{0, -1, 0, 1};

  bool is_safe(int r, int c, vector<vector<int>> &grid/*,
               vector<vector<int>> &visited*/) {
    if (r >= 0 && r < row && c >= 0 && c < col &&
        grid[r][c] == 1 /*&& !visited[r][c]*/)
      return true;
    return false;
  }

  void dfs(int r, int c, vector<vector<int>> &grid,
           /*vector<vector<int>> &visited,*/ int &area) {

    /*visited[r][c] = 1;*/
    grid[r][c] = 2;
    area++;
    // cout << r << ":" << c << "::" << area << endl;
    for (int i = 0; i < 4; i++) {
      int x = r + xaxis[i];
      int y = c + yaxis[i];
      if (is_safe(x, y, grid /*, visited*/)) {
        dfs(x, y, grid, /*visited,*/ area);
      }
    }
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.empty())
      return 0;
    row = grid.size();
    col = grid[0].size();
    // vector<vector<int>> visited(row, vector<int>(col, 0));
    int max_area = 0, area = 0;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (grid[r][c] /*&& !visited[r][c]*/) {
          dfs(r, c, grid, /*visited,*/ area);
          //   cout << endl;
        }
        if (area > max_area) {
          max_area = area;
        }
        area = 0;
      }
      area = 0;
    }
    return max_area;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  Solution sol;
  cout << sol.maxAreaOfIsland(grid) << endl;
  return 0;
}
