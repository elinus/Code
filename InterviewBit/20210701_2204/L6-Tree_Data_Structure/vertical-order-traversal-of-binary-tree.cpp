#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrderTraversal(TreeNode *A) {
  vector<vector<int>> result;
  if (!A)
    return result;
  queue<pair<TreeNode *, int>> qu;
  map<int, vector<int>> ht;
  qu.push({A, 0});
  while (!qu.empty()) {
    pair<TreeNode *, int> p = qu.front();
    qu.pop();
    ht[p.second].push_back(p.first->val);
    if (p.first->left) {
      qu.push({p.first->left, p.second - 1});
    }
    if (p.first->right) {
      qu.push({p.first->right, p.second + 1});
    }
  }
  for (auto it = ht.begin(); it != ht.end(); ++it) {
    result.push_back(move(it->second));
  }
  return result;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
