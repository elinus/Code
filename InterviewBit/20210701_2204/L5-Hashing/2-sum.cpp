vector<int> twoSum(const vector<int> &A, int B) {
  vector<int> ans;
  unordered_map<int, int> ht;
  for (int i = 0; i < A.size(); i++) {
    if (ht.find(B - A[i]) != ht.end()) {
      return {ht[B - A[i]] + 1, i + 1};
    }
    if (ht.find(A[i]) == ht.end()) {
      ht[A[i]] = i;
    }
  }
  return ans;
}
