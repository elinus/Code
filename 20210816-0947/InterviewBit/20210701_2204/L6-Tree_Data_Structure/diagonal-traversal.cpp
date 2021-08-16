#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder_util(TreeNode *root, int key, map<int, vector<int>> &ht) {
  if (root) {
    ht[key].push_back(root->val);
    preorder_util(root->left, key + 1, ht);
    preorder_util(root->right, key, ht);
  }
}

vector<int> solve(TreeNode *A) {
  vector<int> dig;
  if (!A)
    return dig;
  map<int, vector<int>> ht;
  preorder_util(A, 0, ht);
  for (auto it = ht.begin(); it != ht.end(); ++it) {
    for (auto v_it = it->second.begin(); v_it != it->second.end(); ++v_it) {
      dig.push_back(*v_it);
    }
  }
  return dig;
}
