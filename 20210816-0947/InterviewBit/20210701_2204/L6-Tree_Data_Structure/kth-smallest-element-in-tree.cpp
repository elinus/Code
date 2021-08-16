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

void inorder(TreeNode *root, int &smallest, int k, int &it) {
  if (!root)
    return;
  inorder(root->left, smallest, k, it);
  ++it;
  if (it == k) {
    smallest = root->val;
    return;
  }
  inorder(root->right, smallest, k, it);
}
int kthsmallest(TreeNode *root, int k) {
  int smallest = -1;
  int it = 0;
  inorder(root, smallest, k, it);
  return smallest;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
