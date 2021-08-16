#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  bool inorder(TreeNode *root, int l, int r) {
    if (!root)
      return true;
    if (root->val <= l || root->val >= r)
      return false;
    return inorder(root->left, l, root->val) &&
           inorder(root->right, root->val, r);
  }

public:
  bool isValidBST(TreeNode *root) { return inorder(root, INT_MIN, INT_MAX); }
};