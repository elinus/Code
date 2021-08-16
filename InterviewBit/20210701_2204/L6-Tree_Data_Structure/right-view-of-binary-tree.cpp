#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>


using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> solve(TreeNode *A) {
  vector<int> rview;
  if (!A)
    return rview;
  map<int, int> ht;
  queue<TreeNode *> qu;

  qu.push(A);
  qu.push(nullptr);
  int level = 0;
  while (!qu.empty()) {
    TreeNode *node = qu.front();
    qu.pop();
    if (node != nullptr) {
      ht[level] = node->val;
      if (node->left)
        qu.push(node->left);
      if (node->right)
        qu.push(node->right);
    } else {
      if (!qu.empty())
        qu.push(nullptr);
      level++;
    }
  }
  for (auto it = ht.begin(); it != ht.end(); ++it) {
    rview.push_back(it->second);
  }
  return rview;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
