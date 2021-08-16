#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                            {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                            {0, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1}};

int Solve(int Length, string N) {
  vector<int> curr_state = {0, 0, 0, 0, 0, 0, 0};
  int iter_count = 0;
  int count = 0;
  for (int i = 0; i < Length; i++) {
    int num = N[i] - '0';
    for (int j = 0; j < curr_state.size(); j++) {
      if (curr_state[j] != grid[num][j]) {
        iter_count++;
        curr_state[j] = grid[num][j];
      }
    }
    count += iter_count;
    iter_count = 0;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    int Length;
    cin >> Length;
    string N;
    cin >> N;

    int out_;
    out_ = Solve(Length, N);
    cout << out_;
    cout << "\n";
  }
}