#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> Xi(N);
  vector<int> Wi(N);
  for (int i = 0; i < N; i++) {
    cin >> Xi[i];
  }
  int sum = 0;
  int wsum = 0;
  for (int i = 0; i < N; i++) {
    cin >> Wi[i];
    sum += Wi[i];
    wsum += (Xi[i] * Wi[i]);
  }
  cout << fixed << setprecision(1) << (double)wsum / sum << endl;

  return 0;
}
