#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

using namespace std;

class SegmentTree {
private:
  vector<int> tree, in_arr;
  void buildUtil(int start, int end, int st_idx) {
    if (start == end) {
      tree[st_idx] = in_arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    buildUtil(start, mid, st_idx * 2 + 1);
    buildUtil(mid + 1, end, st_idx * 2 + 2);
    tree[st_idx] = tree[st_idx * 2 + 1] + tree[st_idx * 2 + 2];
  }
  void updateUtil(int start, int end, int st_idx, int idx, int diff) {
    if (idx < start || idx > end)
      return;
    tree[st_idx] += diff;
    if (start != end) {
      int mid = start + (end - start) / 2;
      updateUtil(start, mid, 2 * st_idx + 1, idx, diff);
      updateUtil(mid + 1, end, 2 * st_idx + 2, idx, diff);
    }
  }
  int queryUtil(int start, int end, int query_start, int query_end,
                int st_idx) {
    if (query_start <= start && query_end >= end)
      return tree[st_idx];
    if (end < query_start || start > query_end)
      return 0;
    int mid = start + (end - start) / 2;
    return queryUtil(start, mid, query_start, query_end, 2 * st_idx + 1) +
           queryUtil(mid + 1, end, query_start, query_end, 2 * st_idx + 2);
  }

public:
  SegmentTree(const vector<int> &arr) : in_arr(arr) {
    int n = arr.size();

    // height
    int h = ceil(log2(n));
    // max size of segment tree
    int st_max_size = 2 * pow(2, h) - 1;
    tree.resize(st_max_size);
  }
  ~SegmentTree() = default;

  void build() {
    // build segment tree
    int n = in_arr.size();
    buildUtil(0, n - 1, 0);
  }
  void update(int idx, int value) {
    int n = in_arr.size();
    if (idx < 0 || idx > n - 1) {
      cerr << "Invalid index" << endl;
      return;
    }
    int diff = value - in_arr[idx];
    in_arr[idx] = value;
    updateUtil(0, n - 1, 0, idx, diff);
  }
  int query(int start, int end) {
    int n = in_arr.size();
    if (start < 0 || end > n - 1 || start > end) // invalid range
      return 0;
    return queryUtil(0, n - 1, start, end, 0);
  }
  void debug() {
    cout << "Input array:\n";
    copy(in_arr.begin(), in_arr.end(), ostream_iterator<int>(cout, " "));
    cout << "\nSegment tree:\n";
    copy(tree.begin(), tree.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";
    for (int i = 0; i < tree.size(); i++) {
      cout << setw(3) << i << " | " << setw(3) << 2 * i + 1 << " | " << setw(3)
           << 2 * i + 2 << " | " << setw(5) << tree[i] << " | " << endl;
    }
  }
};

int main() {
  //   vector<int> input = {1, 3, 5, 7, 9, 11};
  //   SegmentTree stObj(input);
  //   stObj.build();
  //   stObj.debug();
  //   cout << stObj.query(1, 3) << endl;
  //   stObj.update(1, 10);
  //   cout << stObj.query(1, 3) << endl;
  vector<int> lc_v1 = {1, 3, 5};
  unique_ptr<SegmentTree> ust = unique_ptr<SegmentTree>(new SegmentTree(lc_v1));
  ust->build();
  ust->debug();
  cout << ust->query(0, 2) << endl;
  ust->update(1, 2);
  cout << ust->query(0, 2) << endl;
  return 0;
}