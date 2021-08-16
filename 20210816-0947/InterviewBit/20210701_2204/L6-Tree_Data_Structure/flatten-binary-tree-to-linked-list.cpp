#include <iostream>
#include <map>
#include <queue>
#include <string>
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

void preorder(TreeNode *root, queue<TreeNode *> &q) {
  if (root) {
    q.push(root);
    preorder(root->left, q);
    preorder(root->right, q);
  }
}
TreeNode *flatten(TreeNode *A) {
  if (!A)
    return nullptr;
  queue<TreeNode *> q;
  preorder(A, q);
  TreeNode *prev = nullptr;
  while (!q.empty()) {
    TreeNode *node = q.front();
    if (prev)
      prev->right = node;
    prev = node;
    node->left = nullptr;
    q.pop();
  }
  return A;
}