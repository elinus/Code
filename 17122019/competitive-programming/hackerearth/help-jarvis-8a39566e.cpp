#include <bits/stdc++.h>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    char char_arr[n + 1];
    strcpy(char_arr, s.c_str());

    sort(char_arr, char_arr + n);

    int p = 0;
    for (int i = 1; i < n; i++) {
      if (char_arr[i] != char_arr[i - 1] + 1) {
        p++;
        cout << "NO" << endl;
        break;
      }
    }
    if (p == 0) {
      cout << "YES" << endl;
    }
  }
}
