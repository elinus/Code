#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *A) {
  vector<vector<int>> zz_order;
  if (!A)
    return zz_order;
  stack<TreeNode *> st1, st2;
  st1.push(A);
  vector<int> v;
  while (!st1.empty() || !st2.empty()) {
    while (!st1.empty()) {
      TreeNode *node = st1.top();
      st1.pop();
      v.push_back(node->val);
      if (node->left)
        st2.push(node->left);
      if (node->right)
        st2.push(node->right);
    }
    if (!v.empty())
      zz_order.push_back(move(v));
    while (!st2.empty()) {
      TreeNode *node = st2.top();
      st2.pop();
      v.push_back(node->val);
      if (node->right)
        st1.push(node->right);
      if (node->left)
        st1.push(node->left);
    }
    if (!v.empty())
      zz_order.push_back(move(v));
  }
  return zz_order;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
