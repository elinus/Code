#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *A) {
  vector<int> inorder;
  if (!A)
    return inorder;
  stack<TreeNode *> s;
  while (true) {
    while (A) {
      s.push(A);
      A = A->left;
    }
    if (s.empty())
      break;
    A = s.top();
    s.pop();
    inorder.push_back(A->val);
    A = A->right;
  }
  return inorder;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
