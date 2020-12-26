#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(const vector<T> &v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
  cout << "\n";
}

long long arrayTrip(vector<int> arr, int k) {
  int n = arr.size();
  if (n <= 1)
    return arr[0];
  long long max_sum_so_far = arr[0];
  for (int i = 1; i < n; i++) {
    if ((max_sum_so_far + arr[i]) > max_sum_so_far)
      max_sum_so_far += arr[i];
    else {
      int index = i, max_in_k = INT_MIN;
      for (int j = 0; j < k && (i + j) < n; j++) {
        if (arr[j + i] > max_in_k) {
          max_in_k = arr[j + i];
          index = j + i;
        }
      }
      max_sum_so_far += arr[index];
      i = index;
    }
  }
  return max_sum_so_far;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "r", stdout);
  vector<int> arr1 = {3, 4, -2, 1, 2};
  print(arr1);
  cout << arrayTrip(arr1, 2) << "\n";

  vector<int> arr2 = {0, -3, -2, -5, -7, 1};
  print(arr2);
  cout << arrayTrip(arr2, 3) << "\n";

  vector<int> arr3 = {4, 3, 2, 1, 2};
  print(arr3);
  cout << arrayTrip(arr3, 5) << "\n";

  vector<int> arr4 = {0, -7, -5, -3, -2, 1};
  print(arr4);
  cout << arrayTrip(arr4, 3) << "\n";

  end = chrono::high_resolution_clock::now();
  const chrono::duration<double> elapsedTime = end - start;
  const double seconds = elapsedTime.count();
  cout << "time = " << seconds << " s.\n";
  return 0;
}
