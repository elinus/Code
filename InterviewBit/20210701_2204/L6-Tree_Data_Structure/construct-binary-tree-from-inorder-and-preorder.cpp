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
TreeNode *makeTree(vector<int> &preorder, vector<int> &inorder, int start,
                   int end, int &pre_idx) {
  if (start > end)
    return nullptr;
  TreeNode *node = new TreeNode(preorder[pre_idx++]);
  if (start == end)
    return node;
  int in_idx = findIndex(inorder, start, end, node->val);
  node->left = makeTree(preorder, inorder, start, in_idx - 1, pre_idx);
  node->right = makeTree(preorder, inorder, in_idx + 1, end, pre_idx);
  return node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  if (preorder.empty() || inorder.empty())
    return nullptr;
  int pre_idx = 0;
  return makeTree(preorder, inorder, 0, inorder.size() - 1, pre_idx);
}