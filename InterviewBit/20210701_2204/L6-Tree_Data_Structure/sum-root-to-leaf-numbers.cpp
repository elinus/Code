struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void preorder_util(TreeNode *root, int val, int &sum) {
  if (root) {
    val = (val * 10 + root->val) % 1003;
    if (!root->left && !root->right) {
      sum += val;
    }
    preorder_util(root->left, val, sum);
    preorder_util(root->right, val, sum);
  }
}
int sumNumbers(TreeNode *A) {
  int ans;
  preorder_util(A, 0, ans);
  return ans;
}
