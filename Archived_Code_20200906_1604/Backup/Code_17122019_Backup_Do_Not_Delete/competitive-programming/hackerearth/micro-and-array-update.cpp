#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, K, diff, Ai;
    cin >> N >> K;
    diff = 0;
    for (int i = 0; i < N; ++i) {
      cin >> Ai;
      if ((K - Ai) > diff) {
        diff = K - Ai;
      }
    }
    cout << diff << endl;
  }

  return 0;
}
