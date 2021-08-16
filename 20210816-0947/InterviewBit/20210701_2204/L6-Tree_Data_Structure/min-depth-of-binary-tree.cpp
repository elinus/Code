#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder_util(TreeNode *root, int d, int &mini) {
  if (root) {
    if (!root->left && !root->right) {
      if (d < mini)
        mini = d;
    }
    preorder_util(root->left, d + 1, mini);
    preorder_util(root->right, d + 1, mini);
  }
}

int minDepth(TreeNode *root) {
  if (!root)
    return 0;
  int d = INT_MAX;
  preorder_util(root, 1, d);
  return d;
}