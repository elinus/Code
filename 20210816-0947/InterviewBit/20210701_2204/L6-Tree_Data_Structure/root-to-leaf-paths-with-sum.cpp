#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void preorder_util(TreeNode *root, int target, int curr_sum, vector<int> &path,
                   vector<vector<int>> &ans) {
  if (root) {
    curr_sum += root->val;
    path.push_back(root->val);
    if (!root->left && !root->right && curr_sum == target) {
      ans.push_back(path);
    }
    preorder_util(root->left, target, curr_sum, path, ans);
    preorder_util(root->right, target, curr_sum, path, ans);
    path.pop_back();
  }
}
vector<vector<int>> pathSum(TreeNode *A, int B) {
  vector<vector<int>> ans;
  vector<int> path;
  preorder_util(A, B, 0, path, ans);
  return ans;
}