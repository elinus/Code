#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *A) {
  if (!A)
    return 0;
  int l = maxDepth(A->left);
  int r = maxDepth(A->right);
  return l > r ? l + 1 : r + 1;
}
