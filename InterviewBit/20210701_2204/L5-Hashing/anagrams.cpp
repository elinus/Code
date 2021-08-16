#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> anagrams(const vector<string> &A) {
  vector<vector<int>> ans;
  int n = A.size();
  map<string, vector<int>> ht;
  for (int i = 0; i < A.size(); i++) {
    string word = A[i];
    sort(word.begin(), word.end());
    ht[word].push_back(i + 1);
  }
  for (auto it = ht.begin(); it != ht.end(); ++it) {
    ans.push_back(move(it->second));
  }
  return ans;
}
