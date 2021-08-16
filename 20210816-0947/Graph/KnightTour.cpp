#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
int xcoor[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ycoor[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void print(const vector<vector<int>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << setw(3) << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool valid_coor(int x, int y, const vector<vector<int>> &sol) {
  if (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
    return true;
  return false;
}

bool solve(int x, int y, int move_num, vector<vector<int>> &sol) {
  if (move_num == N * N) {
    return true;
  }
  for (int i = 0; i < N; i++) {
    int nextx = x + xcoor[i];
    int nexty = y + ycoor[i];
    if (valid_coor(nextx, nexty, sol)) {
      sol[nextx][nexty] = move_num;
      if (solve(nextx, nexty, move_num + 1, sol))
        return true;
      else
        sol[nextx][nexty] = -1; // backtrack
    }
  }
  return false;
}

void solveKT() {
  vector<vector<int>> sol(N, vector<int>(N, -1));
  int move_num = 0;
  sol[0][0] = move_num;
  if (solve(0, 0, move_num + 1, sol))
    print(sol);
  else
    cout << "Solution doesn't exist" << endl;
}

int main(int argc, char const *argv[]) {
  solveKT();
  return 0;
}
