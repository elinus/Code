#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(TreeNode *A, TreeNode *B) {
  if (!A)
    return B;
  if (!B)
    return A;
  A->val += B->val;
  A->left = solve(A->left, B->left);
  A->right = solve(A->right, B->right);
  return A;
}
