#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root, int B, vector<int> &trav, vector<int> &path) {
  if (root) {
    trav.push_back(root->val);
    if (root->val == B) {
      path = trav;
      return;
    }
    preorder(root->left, B, trav, path);
    preorder(root->right, B, trav, path);
    trav.pop_back();
  }
}

vector<int> solve(TreeNode *A, int B) {
  vector<int> path, tmp;
  preorder(A, B, tmp, path);
  return path;
}