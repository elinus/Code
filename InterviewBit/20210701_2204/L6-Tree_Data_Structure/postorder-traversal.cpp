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

vector<int> postorderTraversal(TreeNode *A) {
  vector<int> post;
  if (!A)
    return post;
  stack<TreeNode *> s;
  while (true) {
    while (A) {
      post.push_back(A->val);
      s.push(A);
      A = A->right;
    }
    if (s.empty())
      break;
    A = s.top();
    s.pop();

    A = A->left;
  }
  reverse(post.begin(), post.end());
  return post;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
