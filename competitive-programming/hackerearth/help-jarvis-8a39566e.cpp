#include <bits/stdc++.h>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t, n;
  cin >> t;

  while (t--) {
    int arr[10] = {0};
    int mini = INT_MAX;
    int maxi = INT_MIN;

    int rem;
    int quo;
    cin >> n;

    while (n) {
      int rem = n % 10;
      int quo = n / 10;
      arr[rem]++;
      if (rem <= mini) {
        mini = rem;
      }
      if (rem >= maxi) {
        maxi = rem;
      }
      n = quo;
    }

    int flag = 0;
    if (mini == maxi && arr[mini] != 1) {
      flag = 1;
    } else {
      for (int i = mini; i < maxi; i++) {
        if (arr[i] != 1) {
          flag = 1;
          break;
        }
      }
    }

    if (!flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
