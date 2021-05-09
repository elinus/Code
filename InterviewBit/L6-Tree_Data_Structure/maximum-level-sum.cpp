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

int solve(TreeNode *A) {
  if (!A)
    return 0;
  queue<TreeNode *> qu;
  qu.push(A);
  qu.push(nullptr);
  int max_sum = 0, sum = 0;
  while (!qu.empty()) {
    TreeNode *node = qu.front();
    qu.pop();
    if (node) {
      sum += node->val;
      if (node->left)
        qu.push(node->left);
      if (node->right)
        qu.push(node->right);
    } else {
      if (!qu.empty())
        qu.push(nullptr);
      if (max_sum < sum)
        max_sum = sum;
      sum = 0;
    }
  }
  return max_sum;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
