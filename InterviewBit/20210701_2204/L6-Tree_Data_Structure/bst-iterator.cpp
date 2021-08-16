#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<TreeNode *> st;

void push_all_nodes(TreeNode *root) {
  while (root) {
    st.push(root);
    root = root->left;
  }
}

/* BSTIterator:: */ BSTIterator(TreeNode *root) { push_all_nodes(root); }

/** @return whether we have a next smallest number */
bool /* BSTIterator:: */ hasNext() { return !st.empty(); }

/** @return the next smallest number */
int /* BSTIterator:: */ next() {
  TreeNode *node = st.top();
  st.pop();
  push_all_nodes(node->right);
  return node->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
