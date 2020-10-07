#include <iostream>

using namespace std;

int hi[1000001] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  int group = 1;
  for (int i = 0; i < N; ++i) {
    cin >> hi[i];
    if (i > 0 && hi[i] < hi[i - 1]) {
      group++;
    }
  }

  cout << group << "\n";
  return 0;
}
