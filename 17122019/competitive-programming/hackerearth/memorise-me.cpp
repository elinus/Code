#include <iostream>

using namespace std;

int array[1005] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, Ni;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> Ni;
    array[Ni]++;
  }
  int Q, Bi;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> Bi;
    if (array[Bi] > 0) {
      cout << array[Bi] << "\n";
    } else {
      cout << "NOT PRESENT\n";
    }
  }
  return 0;
}
