#include <iostream>

using namespace std;

int arr[1000001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  int mini = -1;

  for (int i = N - 1; i >= 0; i--) {
    if (arr[i] >= mini) {
      mini = arr[i];
    } else {
      arr[i] = -1;
    }
  }
  for (int i = 0; i < N; ++i) {
    if (arr[i] != -1) {
      cout << arr[i] << " ";
    }
  }
  cout << "\n";
  return 0;
}
