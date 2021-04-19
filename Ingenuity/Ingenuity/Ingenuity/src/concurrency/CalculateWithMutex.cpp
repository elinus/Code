#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <vector>

using namespace std;

constexpr long long vec_size = 10000000;
mutex m;
int main() {
  vector<int> randomValues;
  randomValues.resize(vec_size);

  // random
  random_device seed;
  mt19937 engine(seed());
  uniform_int_distribution<int> uniformDist(1, 10);
  for (int i = 0; i < vec_size; i++) {
    randomValues.push_back(uniformDist(engine));
  }
  const auto start = chrono::steady_clock::now();

  unsigned long long sum = {};

  for (auto elem : randomValues) {
    lock_guard<mutex> l(m);
    sum += elem;
  }
  const chrono::duration<double> dur = chrono::steady_clock::now() - start;
  cout << "sum = " << sum << ", duration = " << dur.count() << endl;
  return 0;
}
