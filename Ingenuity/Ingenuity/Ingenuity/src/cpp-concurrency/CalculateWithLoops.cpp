//#include <chrono>
//#include <iostream>
//#include <random>
//#include <vector>
//using namespace std;
//
//constexpr long long size = 100000000;
//
//int main(int argc, char const *argv[]) {
//  vector<int> randomValues;
//  randomValues.resize(size);
//
//  // random
//  random_device seed;
//  mt19937 engine(seed());
//  uniform_int_distribution<int> uniformDist(1, 10);
//  for (int i = 0; i < size; i++) {
//    randomValues.push_back(uniformDist(engine));
//  }
//  const auto start = chrono::steady_clock::now();
//  unsigned long long sum = 0;
//  for (auto elem : randomValues) {
//    sum += elem;
//  }
//  const chrono::duration<double> dur = chrono::steady_clock::now() - start;
//  cout << "sum = " << sum << ", duration = " << dur.count() << endl;
//  return 0;
//}
