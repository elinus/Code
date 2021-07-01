#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> solve(TreeNode *A) {
  vector<int> result;
  if (!A)
    return result;
  queue<TreeNode *> q;
  stack<vector<int>> s;
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
        s.push(level);
      level.clear();
    }
  }
  while (!s.empty()) {
    vector<int> vec = move(s.top());
    s.pop();
    for (auto it = vec.begin(); it != vec.end(); ++it) {
      result.push_back(*it);
    }
  }

  return result;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
