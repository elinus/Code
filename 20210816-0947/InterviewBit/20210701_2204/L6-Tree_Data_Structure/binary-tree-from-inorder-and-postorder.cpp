#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findIndex(const vector<int> &inorder, int start, int end, int val) {
  for (auto idx = start; idx <= end; ++idx)
    if (inorder[idx] == val)
      return idx;
}
TreeNode *makeTree(vector<int> &postorder, vector<int> &inorder, int start,
                   int end, int &post_idx) {
  if (start > end)
    return nullptr;
  TreeNode *node = new TreeNode(postorder[post_idx--]);
  if (start == end)
    return node;
  int in_idx = findIndex(inorder, start, end, node->val);
  node->right = makeTree(postorder, inorder, in_idx + 1, end, post_idx);
  node->left = makeTree(postorder, inorder, start, in_idx - 1, post_idx);

  return node;
}
TreeNode *Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (postorder.empty() || inorder.empty())
    return nullptr;
  int post_idx = postorder.size() - 1;
  return makeTree(postorder, inorder, 0, inorder.size() - 1, post_idx);
}