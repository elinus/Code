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

void preorder_util(TreeNode *root, int target, int curr_sum, bool &ans) {
  if (root) {
    curr_sum += root->val;
    if (!root->left && !root->right && curr_sum == target) {
      ans = true;
      return;
    }
    preorder_util(root->left, target, curr_sum, ans);
    preorder_util(root->right, target, curr_sum, ans);
  }
}

int hasPathSum(TreeNode *A, int B) {
  bool ans;
  preorder_util(A, B, 0, ans);
  return ans;
}
