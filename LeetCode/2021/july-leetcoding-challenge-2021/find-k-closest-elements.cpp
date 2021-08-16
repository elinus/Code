#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int start = 0;
    int end = (int)arr.size() - k;

    while (start < end) {
      int mid = start + (end - start) / 2;

      int rightGap = arr[mid + k] - x;
      int leftGap = x - arr[mid];

      if (rightGap >= leftGap) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    return vector(arr.begin() + start, arr.begin() + start + k);
  }
};