#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else if (s[i] == ')' && !st.empty() && st.top() == '(') {
        st.pop();
      } else if (s[i] == '}' && !st.empty() && st.top() == '{') {
        st.pop();
      } else if (s[i] == ']' && !st.empty() && st.top() == '[') {
        st.pop();
      } else if ((s[i] == ')' || s[i] == '}' || s[i] == ']')) {
        return false;
      }
    }
    if (st.empty())
      return true;
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution obj;
  cout << obj.isValid("{)}") << endl;
  return 0;
}
