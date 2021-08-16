#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    unordered_map<int, int> umap;
    for (int i = 0; i < edges.size(); i++) {
      umap[edges[i][0]]++;
      umap[edges[i][1]]++;
    }
    for (auto it = umap.begin(); it != umap.end(); ++it) {
      if (it->second == edges.size())
        return it->first;
    }
    return -1;
  }
};