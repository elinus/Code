#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &vec) {
  cout << __func__ << endl;
  copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int zero = 0;
    int two = nums.size() - 1;
    int n = nums.size();
    int curr = 0;
    while (curr <= two) {
      if (nums[curr] == 0) {
        swap(nums[curr], nums[zero++]);
        curr++;
      } else if (nums[curr] == 1) {
        curr++;
      } else if (nums[curr] == 2) {
        swap(nums[curr], nums[two--]);
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<int> v1 = {2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(v1);
  cout << "\n\n";
  vector<int> v2 = {1, 2, 0};
  sol.sortColors(v2);
  return 0;
}
