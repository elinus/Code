#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &vec) {
  cout << __func__ << endl;
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 3)
      return res;
    sort(nums.begin(), nums.end());
    set<vector<int>> _set;
    for (int k = 0; k < n - 2; k++) {
      int sum = -nums[k];
      int i = k + 1, j = n - 1;
      while (i < j) {
        int tmp = nums[i] + nums[j];
        if (tmp == sum) {
          vector<int> _vec{nums[k], nums[i], nums[j]};
          sort(_vec.begin(), _vec.end());
          _set.insert(_vec);
        } else if (tmp > sum)
          j--;
        else
          i++;
      }
    }
    // res.insert(res.begin(), _set.begin(), _set.end());
    for (auto it = _set.begin(); it != _set.end(); ++it) {
      res.push_back(*it);
    }
    return res;
  }
};