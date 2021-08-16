#include <iostream>

using namespace std;

int Ai[100005] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, Ni;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> Ni;
    Ai[i] = Ni;
  }
  for (int i = 0; i < N; ++i) {
    cin >> Ni;
    Ai[i] += Ni;
  }
  for (int i = 0; i < N; ++i) {
    cout << Ai[i] << " ";
  }
  cout << "\n";
  return 0;
}
