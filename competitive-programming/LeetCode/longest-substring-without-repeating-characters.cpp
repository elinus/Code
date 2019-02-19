#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int alphabets[26] = {0};
    int i = 0, j = 0;
    int size_ = s.size();
    int max_ = 0;
    while (i < size_ && j < size_) {
      if (!alphabets[s[j] - 'a']) {
        alphabets[s[j++] - 'a'] = 1;
        max_ = max_ > (j - i) ? max_ : j - i;
      } else {
        alphabets[s[i++] - 'a'] = 0;
      }
    }
    return max_;
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
