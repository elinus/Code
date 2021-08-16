#include <iostream>
#include <queue>
#include <vector>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *A) {
  vector<vector<int>> result;
  if (!A)
    return result;
  queue<TreeNode *> q;
  q.push(A);
  q.push(nullptr);
  vector<int> level;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      level.push_back(node->val);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    } else {
      if (!q.empty())
        q.push(nullptr);
      if (!level.empty())
        result.push_back(level);
      level.clear();
    }
  }

  return result;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
