#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    set<char> set_; 
    int i = 0, j = 0;
    int size = s.size();
    if (size == 0) {
        return 0;
    }
    int max = 1;
    while (i < size && j < size) {
      if (set_.find(s[j]) == set_.end()) {
        set_.insert(s[j++]);
        max = max > (j - i) ? max : j - i;
      } else {
        set_.erase(s[i++]);
      }
    }
    return max;
  }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    string ss;
    cin >> ss;
    Solution obj;
    cout << obj.lengthOfLongestSubstring(ss) << endl;
  }

  return 0;
}
