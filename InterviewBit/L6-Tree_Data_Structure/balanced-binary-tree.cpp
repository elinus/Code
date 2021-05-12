#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkBalance(TreeNode *root, int &height) {
  if (root == NULL) {
    height = 0;
    return 1;
  }
  int lh = 0, rh = 0;

  int l = checkBalance(root->left, lh);
  int r = checkBalance(root->right, rh);

  height = (lh > rh ? lh : rh) + 1;

  if (abs(lh - rh) >= 2)
    return 0;
  else
    return l && r;
}

int isBalanced(TreeNode *A) {
  int height = 0;

  return checkBalance(A, height);
}
