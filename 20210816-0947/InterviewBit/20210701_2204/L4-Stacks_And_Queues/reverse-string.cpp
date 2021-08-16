#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string A) {
  stack<char> st;
  string s{""};
  for (auto i = 0; i < A.length(); i++) {
    st.push(A[i]);
  }
  while (!st.empty()) {
    s += st.top();
    st.pop();
  }
  return s;
}

int main(int argc, char const *argv[]) {
  // code
  return 0;
}
