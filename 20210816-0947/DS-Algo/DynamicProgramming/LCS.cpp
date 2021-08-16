#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << "\n";
}

template <typename T> void print(const vector<vector<T>> &v) {
  cout << "v = " << v.size() << "\n";
  for (int r = 0; r < v.size(); r++) {
    copy(v[r].begin(), v[r].end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}

int lcs(const string &x, const string &y, int m, int n) {
  if (m == 0 || n == 0)
    return 0;
  if (x[m - 1] == y[n - 1])
    return 1 + lcs(x, y, m - 1, n - 1);
  else
    return max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
}

int lcs_dp(const string &x, const string &y, int m, int n) {

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {

      if (x[i - 1] == y[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  print(dp);
  return dp[m][n];
}

int main(int argc, char const *argv[]) {
  string X{"AGGTAB"};
  string Y{"GXTXAYB"};
  auto start = chrono::high_resolution_clock::now();
  //   cout << lcs(X, Y, X.length(), Y.length()) << "\n";
  cout << lcs_dp(X, Y, X.length(), Y.length()) << "\n";
  auto finish = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::milliseconds>(finish - start);
  std::cout << "Elapsed Time: " << elapsed.count() << " ms." << std::endl;
  return 0;
}
