#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> find_max_sliding_window(vector<int> &v, int window_size) {
  vector<int> result;
  if (v.size() < window_size) return result;
  deque<int> dq;
  for (int i = 0; i < window_size; i++) {
      while (!dq.empty() && v[i] >= v[dq.back()]) dq.pop_back();
      dq.push_back(i);
  }
  result.push_back(v[dq.front()]);
  for (int i = window_size; i < v.size(); i++) {
      while (!dq.empty() && v[i] >= v[dq.back()]) dq.pop_back();
      while (!dq.empty() && dq.front() <= i - window_size) dq.pop_front();
      dq.push_back(i);
      result.push_back(v[dq.front()]);
  }
  return result;
}