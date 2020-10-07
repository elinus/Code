#include <iostream>

using namespace std;

int arr[10001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  cout << "\n";
  return 0;
}
