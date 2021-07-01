#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &vec) {
  cout << __func__ << endl;
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {

    int n = s1.size(), m = s2.size(), sz = s3.size();
    if (n + m != sz)
      return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
      dp[i][0] = (s1[i - 1] == s3[i - 1]) and dp[i - 1][0];
    }

    for (int j = 1; j <= m; j++) {
      dp[0][j] = (s2[j - 1] == s3[j - 1]) and dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {

        bool matchI = (s1[i - 1] == s3[i + j - 1]) and dp[i - 1][j];
        bool matchJ = (s2[j - 1] == s3[i + j - 1]) and dp[i][j - 1];

        dp[i][j] = matchI or matchJ;
      }
    }

    return dp[n][m];
  }
};

int main(int argc, char const *argv[]) {
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
  Solution sol;
  cout << boolalpha << sol.isInterleave(s1, s2, s3) << endl;
  return 0;
}
