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

vector<int> preorderTraversal(TreeNode *A) {
  vector<int> pre;
  if (!A)
    return pre;
  stack<TreeNode *> s;
  while (true) {
    while (A) {
      pre.push_back(A->val);
      s.push(A);
      A = A->left;
    }
    if (s.empty())
      break;
    A = s.top();
    s.pop();

    A = A->right;
  }
  return pre;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
