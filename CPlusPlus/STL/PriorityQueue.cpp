#include <functional>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

template <typename T> void print_queue(T q) {
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  priority_queue<int> q1; // max heap
  const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
  for (int n : data)
    q1.push(n);
  print_queue(q1);

  priority_queue<int, vector<int>, greater<int>> q2; // min heap
  for (int n : data)
    q2.push(n);
  print_queue(q2);

  auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

  for (int n : data)
    q3.push(n);

  print_queue(q3);
  return 0;
}
