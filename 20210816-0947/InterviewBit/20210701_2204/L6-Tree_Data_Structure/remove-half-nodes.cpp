#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(TreeNode *A) {
  if (!A)
    return nullptr;

  A->left = solve(A->left);
  A->right = solve(A->right);

  if (!A->left && !A->right)
    return A;

  if (!A->left) {
    TreeNode *new_root = A->right;
    delete A;
    return new_root;
  }

  if (!A->right) {
    TreeNode *new_root = A->left;
    delete A;
    return new_root;
  }

  return A;
}
